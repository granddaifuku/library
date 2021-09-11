---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_D.test.cpp
    title: test/aoj/ALDS1_14_D.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"String/SA_IS.cpp\"\n\n\n\n#include <bits/stdc++.h>\n\nusing\
    \ namespace std;\n\nclass SA_IS {\n    public:\n        SA_IS() {}\n\n       \
    \ vector<int> construct(string str) {\n            vector<int> s(str.begin(),\
    \ str.end());\n            return construct(s);\n        }\n\n        vector<int>\
    \ construct(vector<int> s, const int k = 128) {\n            if (s.size() <= 1)\
    \ {\n                return s.empty() ? (vector<int>){0} : (vector<int>){1, 0};\n\
    \            }\n            s.push_back(0);\n            vector<int> bkt(k, 0);\n\
    \            vector<bool> is_stype(s.size());\n\n            // determine S-type\
    \ or L-type\n            for (int i = s.size() - 1; i >= 0; --i) {\n         \
    \       bkt[s[i]]++;\n                is_stype[i] = (i + 1 == s.size()) || (s[i]\
    \ < s[i + 1]) || (s[i] == s[i + 1] && is_stype[i + 1]); \n            }\n    \
    \        for (int i = 1; i < k; ++i) bkt[i] += bkt[i - 1];\n\n            // Induced\
    \ Sorting with wrong seed\n            vector<int> b(bkt);\n            \n   \
    \         vector<int> sa(s.size()), is_lms(s.size());\n            int lms_cnt\
    \ = 0;\n            for (int i = 1; i < s.size(); ++i) {\n                if (!is_stype[i\
    \ - 1] && is_stype[i]) {\n                    is_lms[i] = 1;\n               \
    \     sa[--bkt[s[i]]] = i;\n                    lms_cnt++;\n                }\n\
    \            }\n            \n            sa = inducedSort(s, sa, is_stype, b);\n\
    \n            int lms_substr = 1, pre = -1;\n            is_lms[sa[0]] = lms_substr++;\n\
    \            for (int i = 1; i < sa.size(); ++i) {\n                if (!is_lms[sa[i]])\
    \ continue;\n                if (pre >= 0 && s[pre] == s[sa[i]]) {\n         \
    \           int k;\n                    for (k = 1; s[pre + k] == s[sa[i] + k]\
    \ && !is_lms[pre + k] && !is_lms[sa[i] + k]; ++k) ;\n                    lms_substr\
    \ -= (s[pre + k] == s[sa[i] + k] && is_lms[pre + k] && is_lms[sa[i] + k]);\n \
    \               }\n                pre = sa[i];\n                is_lms[sa[i]]\
    \ = lms_substr++;\n            }\n\n            vector<int> newstr(lms_cnt), rev(lms_cnt);\n\
    \            int cnt = 0;\n            for (int i = 0; i < s.size(); ++i) {\n\
    \                if (!is_lms[i]) continue;\n                newstr[cnt] = is_lms[i];\n\
    \                rev[cnt] = i;\n                cnt++;\n            }\n\n    \
    \        vector<int> sorted_lms = construct(newstr, lms_substr);\n           \
    \ sa.assign(s.size(), 0);\n            for (int i = 1; i < sorted_lms.size();\
    \ ++i) {\n                int j = rev[sorted_lms[i]];\n                sa[bkt[s[j]]++]\
    \ = j;\n            }\n\n            return inducedSort(s, sa, is_stype, b);\n\
    \        }\n\n        vector<int> inducedSort(const vector<int>& s, const vector<int>&sa,\
    \ const vector<bool>& is_stype, vector<int> bkt) {\n            int n = sa.size();\n\
    \            vector<int> b(bkt), res(n);\n            res[0] = sa[0];\n      \
    \      for (int i = 0; i < n; ++i) {\n                int j = sa[i] - 1, k = res[i]\
    \ - 1;\n                if (j >= 0 && !is_stype[j]) res[b[s[j] - 1]++] = j;\n\
    \                else if (k >= 0 && !is_stype[k]) res[b[s[k] - 1]++] = k;\n  \
    \          }\n            for (int i = n - 1; i >= 0; --i) {\n               \
    \ int j = res[i] - 1;\n                if (j >= 0 && is_stype[j]) res[--bkt[s[j]]]\
    \ = j;\n            }\n\n            return res;\n        }\n\n        bool contain(string\
    \ s, string t, const vector<int>& sa) {\n            int l = 0, r = sa.size(),\
    \ m;\n            while (r - l > 1) {\n                m = (l + r) / 2;\n    \
    \            if (s.substr(sa[m], t.size()) <= t) l = m;\n                else\
    \ r = m;\n            }\n\n            return s.substr(sa[l], t.size()) == t;\n\
    \        }\n};\n\n\n"
  code: "#ifndef H_SA_IS\n#define H_SA_IS\n\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\nclass SA_IS {\n    public:\n        SA_IS() {}\n\n        vector<int>\
    \ construct(string str) {\n            vector<int> s(str.begin(), str.end());\n\
    \            return construct(s);\n        }\n\n        vector<int> construct(vector<int>\
    \ s, const int k = 128) {\n            if (s.size() <= 1) {\n                return\
    \ s.empty() ? (vector<int>){0} : (vector<int>){1, 0};\n            }\n       \
    \     s.push_back(0);\n            vector<int> bkt(k, 0);\n            vector<bool>\
    \ is_stype(s.size());\n\n            // determine S-type or L-type\n         \
    \   for (int i = s.size() - 1; i >= 0; --i) {\n                bkt[s[i]]++;\n\
    \                is_stype[i] = (i + 1 == s.size()) || (s[i] < s[i + 1]) || (s[i]\
    \ == s[i + 1] && is_stype[i + 1]); \n            }\n            for (int i = 1;\
    \ i < k; ++i) bkt[i] += bkt[i - 1];\n\n            // Induced Sorting with wrong\
    \ seed\n            vector<int> b(bkt);\n            \n            vector<int>\
    \ sa(s.size()), is_lms(s.size());\n            int lms_cnt = 0;\n            for\
    \ (int i = 1; i < s.size(); ++i) {\n                if (!is_stype[i - 1] && is_stype[i])\
    \ {\n                    is_lms[i] = 1;\n                    sa[--bkt[s[i]]] =\
    \ i;\n                    lms_cnt++;\n                }\n            }\n     \
    \       \n            sa = inducedSort(s, sa, is_stype, b);\n\n            int\
    \ lms_substr = 1, pre = -1;\n            is_lms[sa[0]] = lms_substr++;\n     \
    \       for (int i = 1; i < sa.size(); ++i) {\n                if (!is_lms[sa[i]])\
    \ continue;\n                if (pre >= 0 && s[pre] == s[sa[i]]) {\n         \
    \           int k;\n                    for (k = 1; s[pre + k] == s[sa[i] + k]\
    \ && !is_lms[pre + k] && !is_lms[sa[i] + k]; ++k) ;\n                    lms_substr\
    \ -= (s[pre + k] == s[sa[i] + k] && is_lms[pre + k] && is_lms[sa[i] + k]);\n \
    \               }\n                pre = sa[i];\n                is_lms[sa[i]]\
    \ = lms_substr++;\n            }\n\n            vector<int> newstr(lms_cnt), rev(lms_cnt);\n\
    \            int cnt = 0;\n            for (int i = 0; i < s.size(); ++i) {\n\
    \                if (!is_lms[i]) continue;\n                newstr[cnt] = is_lms[i];\n\
    \                rev[cnt] = i;\n                cnt++;\n            }\n\n    \
    \        vector<int> sorted_lms = construct(newstr, lms_substr);\n           \
    \ sa.assign(s.size(), 0);\n            for (int i = 1; i < sorted_lms.size();\
    \ ++i) {\n                int j = rev[sorted_lms[i]];\n                sa[bkt[s[j]]++]\
    \ = j;\n            }\n\n            return inducedSort(s, sa, is_stype, b);\n\
    \        }\n\n        vector<int> inducedSort(const vector<int>& s, const vector<int>&sa,\
    \ const vector<bool>& is_stype, vector<int> bkt) {\n            int n = sa.size();\n\
    \            vector<int> b(bkt), res(n);\n            res[0] = sa[0];\n      \
    \      for (int i = 0; i < n; ++i) {\n                int j = sa[i] - 1, k = res[i]\
    \ - 1;\n                if (j >= 0 && !is_stype[j]) res[b[s[j] - 1]++] = j;\n\
    \                else if (k >= 0 && !is_stype[k]) res[b[s[k] - 1]++] = k;\n  \
    \          }\n            for (int i = n - 1; i >= 0; --i) {\n               \
    \ int j = res[i] - 1;\n                if (j >= 0 && is_stype[j]) res[--bkt[s[j]]]\
    \ = j;\n            }\n\n            return res;\n        }\n\n        bool contain(string\
    \ s, string t, const vector<int>& sa) {\n            int l = 0, r = sa.size(),\
    \ m;\n            while (r - l > 1) {\n                m = (l + r) / 2;\n    \
    \            if (s.substr(sa[m], t.size()) <= t) l = m;\n                else\
    \ r = m;\n            }\n\n            return s.substr(sa[l], t.size()) == t;\n\
    \        }\n};\n\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: String/SA_IS.cpp
  requiredBy: []
  timestamp: '2020-06-22 15:58:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_14_D.test.cpp
documentation_of: String/SA_IS.cpp
layout: document
redirect_from:
- /library/String/SA_IS.cpp
- /library/String/SA_IS.cpp.html
title: String/SA_IS.cpp
---
