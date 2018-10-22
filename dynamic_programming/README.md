# DP

---

## 最长回文子串(logest_palindrome.cpp)

分析 : 

```

设 S 为字符集合 {s[1], s[2], ..., s[n]}
S[i, j] 为字符集 S 的子串 {s[i], s[i + 1], ..., s[j - 1], s[j]}, 1 <= i <= j <= n;
A[i, j] 为子字符集 S[i, j] 的一个最大回文字符集 {a[1], ..., a[k]}, a[k] 属于 S[i, j];

当 s[i] == s[j] 时, A[i,j] 为 S[i,j] 的一个最大子回文字符集，
则其子字符串 S[i + 1, j - 1] 的最大子字符串 A[i + 1, j - 1] U {s[i], s[j]} = A[i,j]。
若 s[i] != s[j] 时, A[i][j] = max(A[i, j - 1], A[i + 1, j - 1])

则有 A[i][j] = s[i] U A[i + 1][j - 1] U s[j],            (s[i] == s[j]),
               max(A[i, j - 1], A[i + 1, j])             (s[i] != s[j]),

其中如果 i == j, A[i][j] = s[i] or s[j];

```

---
