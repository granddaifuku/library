---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: DataStructure/segment_tree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/segment_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-22 15:03:42+09:00




## Required by

* :warning: <a href="../test/aoj/DSL_2_A.cpp.html">test/aoj/DSL_2_A.cpp</a>
* :warning: <a href="../test/aoj/DSL_2_B.cpp.html">test/aoj/DSL_2_B.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef H_segment_tree
#define H_segment_tree

#include <bits/stdc++.h>

using namespace std;

template <typename T>
class SegmentTree {
    public:
        int n;
        T e;
        vector<T> node;
        function<T(T, T)> operation;
        function<T(T, T)> process;

        SegmentTree() {}
        SegmentTree(int n_, T e_, function<T(T, T)> operation_, 
            function<T(T, T)> process_) : e(e_), operation(operation_), process(process_) {
            n = 1;
            while (n < n_) n <<= 1;
            node.assign(2 * n, e);
        }

        void build() {
            for (int i = n - 1; i > 0; --i) {
                node[i] = operation(node[i * 2 + 0], node[i * 2 + 1]);
            }
        }

        void set(int idx, T v) {
            node[idx + n] = process(node[idx + n], v);
        }

        void update(int idx, T v) {
            idx += n;
            node[idx] = process(node[idx], v);
            while (idx >>= 1) {
                node[idx] = operation(node[idx * 2 + 0], node[idx * 2 + 1]);
            }
        }

        T query(int a, int b) {
            return query(a, b + 1, 1, 0, n);
        }

        T query(int a, int b, int k, int l, int r) {
            if (a >= r || b <= l) return e;
            if (a <= l && b >= r) return node[k];
            T c = query(a, b, 2 * k + 0, l, (l + r) / 2);
            T d = query(a, b, 2 * k + 1, (l + r) / 2, r);

            return operation(c, d);
        }

        T operator[](int idx) {
            return node[idx + n];
        }
};

#endif
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/segment_tree.cpp"



#include <bits/stdc++.h>

using namespace std;

template <typename T>
class SegmentTree {
    public:
        int n;
        T e;
        vector<T> node;
        function<T(T, T)> operation;
        function<T(T, T)> process;

        SegmentTree() {}
        SegmentTree(int n_, T e_, function<T(T, T)> operation_, 
            function<T(T, T)> process_) : e(e_), operation(operation_), process(process_) {
            n = 1;
            while (n < n_) n <<= 1;
            node.assign(2 * n, e);
        }

        void build() {
            for (int i = n - 1; i > 0; --i) {
                node[i] = operation(node[i * 2 + 0], node[i * 2 + 1]);
            }
        }

        void set(int idx, T v) {
            node[idx + n] = process(node[idx + n], v);
        }

        void update(int idx, T v) {
            idx += n;
            node[idx] = process(node[idx], v);
            while (idx >>= 1) {
                node[idx] = operation(node[idx * 2 + 0], node[idx * 2 + 1]);
            }
        }

        T query(int a, int b) {
            return query(a, b + 1, 1, 0, n);
        }

        T query(int a, int b, int k, int l, int r) {
            if (a >= r || b <= l) return e;
            if (a <= l && b >= r) return node[k];
            T c = query(a, b, 2 * k + 0, l, (l + r) / 2);
            T d = query(a, b, 2 * k + 1, (l + r) / 2, r);

            return operation(c, d);
        }

        T operator[](int idx) {
            return node[idx + n];
        }
};



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

