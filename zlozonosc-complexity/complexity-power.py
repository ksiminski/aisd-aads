# Algorithm and data structures 




def powers () : 
    
    def measure_time (func, ** kwargs) :
        import time
        times = []
        for n in kwargs['ns'] :
            x = kwargs['x']
            start = time.time()
            func (x, n)
            stop = time.time()
            elapsed = stop - start
            times.append (elapsed)
        return ns, times 


    def power_linear (x, n) : 
        result = 1 
        for i in range (n) : 
            result *= x
        return result 

    def power_split (x, n) : 
        if n == 0 : 
            return 1
        if n == 1 : 
            return x
        if n % 2 == 0 : 
            return power_split(x * x, n // 2)
        else : 
            return x * power_split (x * x, n // 2)


    x = 1.000000000001
    # Create a list of n values:
    ns = [ 1000, 2000, 3000, 4000, 5000]

    power_linear_time = measure_time (power_linear, ns = ns, x = x)
    power_split_time  = measure_time (power_split,  ns = ns, x = x)

    # plot the results
    import matplotlib.pyplot as plt 
    plt.plot(ns, power_linear_time[0], label = 'linear')
    plt.plot(ns, power_split_time[1],  label = 'split')
    plt.xlabel('n')
    plt.ylabel('time')
    plt.title('Power evaluation')
    plt.legend()
    plt.show()

if __name__ == "__main__" : 
    powers()

