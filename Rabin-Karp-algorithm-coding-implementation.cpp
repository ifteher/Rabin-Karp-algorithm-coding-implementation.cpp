#include <bits/stdc++.h>
// A header file that includes most commonly used libraries in C++.
// Provides a concise way to use the STL and other standard functionalities.

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// These are for advanced data structures like ordered sets/maps, not used here.

#define ll long long int          // Alias for long long integer.
#define ull unsigned ll           // Alias for unsigned long long integer.
#define lld double                // Alias for double.
#define str_lwr(x) transform(x.begin(),x.end(),x.begin(),::towlower)  // Converts a string to lowercase.
#define str_upr(x) transform(x.begin(),x.end(),x.begin(),::towupper)  // Converts a string to uppercase.

#define tc ll t; in t; while(t--) // Used to process multiple test cases.

#define vec(b,a,n) vector<b>a(n)      // Macro to define a vector of type `b` with size `n`.
#define mpi(a,b,mp) map<a,b>mp        // Macro to define a map with key type `a` and value type `b`.
#define mi(mp) mp.insert              // Shortcut for `map.insert()`.
#define vecbool(is_prime,n) vector<bool>is_prime(n+1,true) // Boolean vector, useful for sieve.

#define pb push_back                 // Shortcut for pushing elements to a vector.
#define it(a) for(auto it : a)out it<<(char)32;  // Iterate through `a` and output elements.
#define new out endl                 // Shortcut for `cout << endl`.
#define vecp(b) vector<pair<ll,ll>>b // Vector of pairs with `ll` as type.
#define iit(b) for(auto iit : b)out iit.first<<(char)32<<iit.second<<(char)32; // Iterate over vector of pairs.

#define gcd __gcd                    // Shortcut for the built-in GCD function.
#define in cin>>                     // Shortcut for `cin >>`.
#define out cout<<                   // Shortcut for `cout <<`.
#define loopi(a,b,c) for(ll i=a;i<b;i+=c) // Macro for `for` loop incrementing `i` by `c`.
#define loopj(a,b,c) for(ll j=a;j<b;j+=c) // Macro for `for` loop incrementing `j` by `c`.
#define rloopi(a,b,c) for(ll i=a;i>=b;i-=c) // Macro for reverse `for` loop decrementing `i` by `c`.

#define all(a) a.begin(),a.end()      // Shortcut for `begin()` and `end()`.
#define max_value(a) *max_element(a.begin(),a.end())  // Maximum value in a container.
#define max_index(a) max_element(a.begin(),a.end())-a.begin() // Index of max value.
#define min_value(a) *min_element(a.begin(),a.end())  // Minimum value in a container.
#define min_index(a) min_element(a.begin(),a.end())-a.begin() // Index of min value.
#define b_s(a,x) binary_search(a.begin(),a.end(),x) // Binary search in a sorted container.
#define free(a,x1) count(a.begin(),a.end(),x1) // Count occurrences of `x1` in container.
#define nsort(a) sort(a.begin(),a.end())      // Sort container in ascending order.
#define rsort(a) sort(a.rbegin(),a.rend())    // Sort container in descending order.

#define PM_RIFAT ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
// Improves I/O performance by disabling C-style synchronization and untangling `cin` and `cout`.

#define M 1000000007               // A large prime modulus for hash calculations.
// #define ordered_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
// Data structure for ordered sets/maps (commented out here).

using namespace std;
// using namespace __gnu_pbds; // Namespace for policy-based data structures (commented out).

#define base 53                    // Base for polynomial rolling hash.

const ll n=1e6+5;                  // Size limit for arrays/vectors.

ll hash_value(ll a, ll b) {
    ll res=((a%M)*(b%M))%M;       // Computes modular multiplication.
    if(res<0) res+=M;             // Ensures positive result.
    return res;
}

ll char_to_int(char ch) {
    return (ch-'a'+1);            // Maps a character ('a'-'z') to a number (1-26).
}

int main() {
    PM_RIFAT;                     // Optimize I/O performance.
    string x, y; in x >> y;       // Input two strings: `x` (text) and `y` (pattern).

    ll s = x.size(), t = y.size(), h_t = 0;  // Lengths of text and pattern; `h_t` is hash of pattern.
    vector<ll> h(n, 0), power(n);           // `h` stores prefix hashes, `power` stores powers of base.
    power[0] = 1;

    // Precompute powers of the base modulo `M`.
    for (ll i = 1; i < n; i++) {
        power[i] = ((power[i-1] % M) * (base % M)) % M;
    }

    // Compute prefix hashes for text `x`.
    for (ll i = 0; i < x.size(); i++) {
        h[i+1] = ((h[i] % M) + (hash_value(char_to_int(x[i]), power[i]) % M)) % M;
    }

    // Compute the hash of pattern `y`.
    for (ll i = 0; i < y.size(); i++) {
        h_t = ((h_t % M) + (hash_value(char_to_int(y[i]), power[i])) % M) % M;
    }

    ll l = 0, r = t, ans = 0; // Sliding window: `l` is left, `r` is right, `ans` counts matches.

    while (r <= s) {
        // Current substring hash.
        ll cur = (h[r] - h[l] + M) % M;

        // Compare with pattern hash.
        if (cur == (h_t * power[l] % M)) {
            ++ans;                // Match found; increment count.
        }
        ++r, ++l;                 // Move the window.
    }

    out ans;                      // Output the count of occurrences.
    return 0;
}
