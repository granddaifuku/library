#ifndef H_SA_IS
#define H_SA_IS

#include <bits/stdc++.h>

using namespace std;

class SA_IS {
    public:
        SA_IS() {}

        vector<int> construct(string str) {
            vector<int> s(str.begin(), str.end());
            return construct(s);
        }

        vector<int> construct(vector<int> s, const int k = 128) {
            if (s.size() <= 1) {
                return s.empty() ? (vector<int>){0} : (vector<int>){1, 0};
            }
            s.push_back(0);
            vector<int> bkt(k, 0);
            vector<bool> is_stype(s.size());

            // determine S-type or L-type
            for (int i = s.size() - 1; i >= 0; --i) {
                bkt[s[i]]++;
                is_stype[i] = (i + 1 == s.size()) || (s[i] < s[i + 1]) || (s[i] == s[i + 1] && is_stype[i + 1]); 
            }
            for (int i = 1; i < k; ++i) bkt[i] += bkt[i - 1];

            // Induced Sorting with wrong seed
            vector<int> b(bkt);
            
            vector<int> sa(s.size()), is_lms(s.size());
            int lms_cnt = 0;
            for (int i = 1; i < s.size(); ++i) {
                if (!is_stype[i - 1] && is_stype[i]) {
                    is_lms[i] = 1;
                    sa[--bkt[s[i]]] = i;
                    lms_cnt++;
                }
            }
            
            sa = inducedSort(s, sa, is_stype, b);

            int lms_substr = 1, pre = -1;
            is_lms[sa[0]] = lms_substr++;
            for (int i = 1; i < sa.size(); ++i) {
                if (!is_lms[sa[i]]) continue;
                if (pre >= 0 && s[pre] == s[sa[i]]) {
                    int k;
                    for (k = 1; s[pre + k] == s[sa[i] + k] && !is_lms[pre + k] && !is_lms[sa[i] + k]; ++k) ;
                    lms_substr -= (s[pre + k] == s[sa[i] + k] && is_lms[pre + k] && is_lms[sa[i] + k]);
                }
                pre = sa[i];
                is_lms[sa[i]] = lms_substr++;
            }

            vector<int> newstr(lms_cnt), rev(lms_cnt);
            int cnt = 0;
            for (int i = 0; i < s.size(); ++i) {
                if (!is_lms[i]) continue;
                newstr[cnt] = is_lms[i];
                rev[cnt] = i;
                cnt++;
            }

            vector<int> sorted_lms = construct(newstr, lms_substr);
            sa.assign(s.size(), 0);
            for (int i = 1; i < sorted_lms.size(); ++i) {
                int j = rev[sorted_lms[i]];
                sa[bkt[s[j]]++] = j;
            }

            return inducedSort(s, sa, is_stype, b);
        }

        vector<int> inducedSort(const vector<int>& s, const vector<int>&sa, const vector<bool>& is_stype, vector<int> bkt) {
            int n = sa.size();
            vector<int> b(bkt), res(n);
            res[0] = sa[0];
            for (int i = 0; i < n; ++i) {
                int j = sa[i] - 1, k = res[i] - 1;
                if (j >= 0 && !is_stype[j]) res[b[s[j] - 1]++] = j;
                else if (k >= 0 && !is_stype[k]) res[b[s[k] - 1]++] = k;
            }
            for (int i = n - 1; i >= 0; --i) {
                int j = res[i] - 1;
                if (j >= 0 && is_stype[j]) res[--bkt[s[j]]] = j;
            }

            return res;
        }

        bool contain(string s, string t, const vector<int>& sa) {
            int l = 0, r = sa.size(), m;
            while (r - l > 1) {
                m = (l + r) / 2;
                if (s.substr(sa[m], t.size()) <= t) l = m;
                else r = m;
            }

            return s.substr(sa[l], t.size()) == t;
        }
};

#endif