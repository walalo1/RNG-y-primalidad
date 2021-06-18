bool millerTest(ZZ d, ZZ n) {
 
    ZZ a = ZZ(2) + aleatorio(ZZ(0), (n - ZZ(4));
    ZZ x = potenciaBinaria(a, d, n);
     if (x == ZZ(1)  || x == n - ZZ(1))
       return true;
 
    while (d != n - ZZ(1)) {
        x = (x * x) % n;
        d *= ZZ(2);
         if (x == ZZ(1))      return false;
        if (x == n - ZZ(1))    return true;
    }
     return false;
}
