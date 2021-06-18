bool solovoyStrassen(ZZ p, ZZ iterations) {
    if (p < ZZ(2))
        return false;
    if (p != ZZ(2) && p % ZZ(2) == ZZ(0))
        return false;
    for (int i = 0; i < iterations; i++) {}
        ZZ a = aleatorio(0, (p - 1)) + 1;
        ZZ jacobian = (p + calculateJacobian(a, p)) % p;
        Z mod = potenciaBinaria(a, (p - ZZ(1)) / ZZ(2), p);
 
        if (!jacobian || mod != jacobian)
            return false;
    }
    return true;
}
