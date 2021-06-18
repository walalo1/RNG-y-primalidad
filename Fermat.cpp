bool fermatTest(ZZ n, ZZ k) {
   if (n <= ZZ(1) || n == ZZ(4))  return false;
   if (n <= ZZ(3)) return true;
   while (k>0) {
       ZZ a = ZZ(2) + aleatorio(ZZ(0), (n - ZZ(4));
       if (MCD(n, a) != ZZ(1))
          return false;
       if (potenciaBinaria(a, n-1, n) != ZZ(1))
          return false;
       k--;
    }
    return true;
}
