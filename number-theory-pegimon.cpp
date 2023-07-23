
int lcm(int a,int b){
    return a*b / __gcd(a,b);
}
int fact(int a){
    if(a==0 || a==1) return 1;
    return (a*fact(a-1))%1000000007;
}
int ncr(int n,int r){
    return (fact(n)/ (fact(r)*fact(n-r)))%1000000007;
}
ll nc2(ll n){
    return (n * (n - 1) / 2);
}

vector<pair<ll, ll>>primeFactorization(ll n){ // O(sqrt(n))
    vector<pair<ll, ll>>v;
    if(n % 2 == 0){
        int cnt = 0;
        while (n % 2 == 0) n /= 2, cnt++;
        v.emplace_back(2, cnt);
    }
    for(ll i = 3; i * i <= n; i += 2){
        if(n % i == 0){
            int cnt = 0;
            while (n % i == 0) n /= i, cnt++;
            v.emplace_back(i, cnt);
        }
    }
    if(n > 1) v.emplace_back(n, 1);
    return v;
}
vector<ll> getDivisors(ll n){ // O(sqrt(n))
    vector<ll>d;
    for(ll i = 1; i * i <= n; i++){
        if(n % i == 0) {
            d.emplace_back(i);
            if(i != n / i)
                d.emplace_back(n / i);
        }
    }
    return d;
}

const int N_MAX = 1e6+10000;
int prime[N_MAX];
void sieve(int n){
    for(int i = 2; i <= n; i++) prime[i] = 1;

    for(int j = 4; j <= n; j += 2)
        prime[j] = 0;

    for(ll i = 3; i <= n; i += 2)
        if(prime[i])
            for(ll j = i * i; j <= n; j += i)
                prime[j] = 0;
}

int N_MAX_2 = 1e8;
bitset<N_MAX_2> bits;
void sieve(int n){
   bits.set();
   bits[0] = bits[1] = 0;
   for (int i = 2; i * i <= n; i++) {
       if (bits[i]) {
           for (int j = i * i; j <= n; j += i) bits[j] = 0;
       }
   }
}

ll fastPower(ll number,ll power){
    if(power == 0) return 1;

    ll ret = fastPower(number,power>>1);
    ret *= ret;
    if (power & 1)
        ret *= number;
    return ret;
}

ll add(ll a, ll b, ll m){
    return ((a % m) + (b % m)) % m;
}
ll sub(ll a, ll b, ll m){
    return ((a % m) - (b % m) + m) % m;
}
ll mul(ll a, ll b, ll m){
    return ((a % m) * (b % m)) % m;
}

// fast power
ll fp(ll b, ll p, ll m){ // O(log(p))
    // base case
    if(!p) return 1;
 
    // transition
    ll ret = fp(b, p >> 1, m);
    ret = mul(ret, ret, m);
    if(p & 1) ret = mul(ret, b, m);
    return ret;
}

ll modInv(ll x, ll m){
    return fp(x, m - 2, m);
}

ll div(ll a, ll b, ll m) { // NOTE: m MUST BE PRIME NUMBER
    return mul(a, modInv(b, m), m);
}

ll fact[N];
void pre(int m){
    fact[0] = fact[1] = 1;
    for(int i = 2; i < N; i++)
         fact[i] = mul(fact[i - 1], i, m);
}
 
ll ncr(ll n, ll r, ll m){ // n! / (r! * (n - r)!)
    if(n < r) return 0;
    return mul(mul(fact[n], modInv(fact[r], m), m), modInv(fact[n - r], m), m);
}
 
ll npr(ll n, ll r, ll m){ // n! / (n - r)!
    if(n < r) return 0;
    return mul(fact[n], modInv(fact[n - r], m), m);
}
