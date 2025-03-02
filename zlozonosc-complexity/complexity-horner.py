# Algorithm and data structures 
# Lec01 
# 2025-03-03


def polynomials () : 
    def direct (coeffs, x) :
        W = coeffs[0] 
        for i in range (1, len(coeffs)) :
            p = x 
            for j in range (i - 1) :
                p *= x
            W += coeffs[i] * p
        return W 

    def horner (coeffs, x) :
        W = 0
        for i in range (len(coeffs)-1, -1, -1) :
            W = W * x + coeffs[i]
        return W

    # measure execution time
    def create_polynomial_coefficients (n) :
        import numpy as np
        return [ np.random.uniform(-1, 1) for i in range (n) ]
    
    def measure_time (func, ** kwargs) :
        import time
        times = []
        for n in kwargs['ns'] :
            coeffs = create_polynomial_coefficients(n)
            x = kwargs['x']
            start = time.time()
            func (coeffs, x)
            stop = time.time()
            elapsed = stop - start
            times.append (elapsed)
        return ns, times 


    x = -3.14159
    # Create a list of n values:
    ns = [ 100, 200, 300, 400, 500]

    direct_time = measure_time (direct, ns = ns, x = x)
    horner_time = measure_time (horner, ns = ns, x = x)

    # plot the results
    import matplotlib.pyplot as plt 
    plt.plot(ns, direct_time[1], label = 'direct')
    plt.plot(ns, horner_time[1], label = 'horner')
    plt.xlabel('n')
    plt.ylabel('time')
    plt.title('Polynomial evaluation')
    plt.legend()
    plt.show()

if __name__ == "__main__" : 
    polynomials()

