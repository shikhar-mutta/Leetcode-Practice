#include <bits/stdc++.h>
using namespace std;

// Global arrays at stated limits
char          g_char  [100000000];  // 10^8 = 100 MB
int           g_int   [10000000];   // 10^7 =  40 MB
float         g_float [10000000];   // 10^7 =  40 MB
long long     g_ll    [10000000];   // 10^7 =  80 MB
double        g_double[10000000];   // 10^7 =  80 MB
pair<int,int> g_pair  [10000000];   // 10^7 =  80 MB

// Each in its own function — separate stack frames
void local_char()   { char      a[1000000]; a[0]='A'; printf("  char[10^6]    ( 1 MB) : OK\n"); }
void local_int()    { int       a[1000000]; a[0]=1;   printf("  int[10^6]     ( 4 MB) : OK\n"); }
void local_float()  { float     a[1000000]; a[0]=1.f; printf("  float[10^6]   ( 4 MB) : OK\n"); }
void local_ll()     { long long a[1000000]; a[0]=1;   printf("  ll[10^6]      ( 8 MB) : OK\n"); }
void local_double() { double    a[1000000]; a[0]=1.0; printf("  double[10^6]  ( 8 MB) : OK\n"); }

// Overflow: 40 MB on stack — expect segfault
void local_overflow() { int a[10000000]; a[0]=1; printf("  int[10^7] (40 MB) : OK (unexpected!)\n"); }

int main() {
    setbuf(stdout, NULL); // disable buffering so output shows even before segfault

    // Global writes — touch first and last element of each array
    g_char[0]='A';   g_char[99999999]='Z';
    g_int[0]=1;      g_int[9999999]=1;
    g_float[0]=1.f;  g_float[9999999]=1.f;
    g_ll[0]=1;       g_ll[9999999]=1;
    g_double[0]=1.0; g_double[9999999]=1.0;
    g_pair[0]={1,1}; g_pair[9999999]={1,1};

    printf("Stack on this machine: ~12 MB (ulimit -s = 12500 KB)\n\n");

    printf("=== GLOBAL arrays (256 MB limit) ===\n");
    printf("  char[10^8]          (100 MB) : OK\n");
    printf("  int[10^7]           ( 40 MB) : OK\n");
    printf("  float[10^7]         ( 40 MB) : OK\n");
    printf("  long long[10^7]     ( 80 MB) : OK\n");
    printf("  double[10^7]        ( 80 MB) : OK\n");
    printf("  pair<int,int>[10^7] ( 80 MB) : OK\n");

    printf("\n=== LOCAL arrays at 10^6 (each in own stack frame) ===\n");
    local_char();
    local_int();
    local_float();
    local_ll();
    local_double();

    printf("\n=== LOCAL int[10^7] = 40 MB (expect segfault) ===\n");
    local_overflow();

    printf("(never reached)\n");
    return 0;
}
