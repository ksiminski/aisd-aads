# Algorithm and data structures 
# Lec01 
# 2025-03-03

def stars (): 
    def stars_1 (n) :
        for i in range (n) :
            for j in range (n) : 
                print ('*', end = '')
            print ()

    def stars_2 (n) :
        for i in range (n) :
            for j in range (i) :
                print ('*', end = '')
            print ()

    def measure_time (func, ns) :
        import time
        times = []
        for n in ns :
            start = time.time()
            func (n)
            stop = time.time()
            elapsed = stop - start
            times.append (elapsed)
        return ns, times 

    # measure execution time
    ns = [ 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000 ]
    time_stars_1 = measure_time (stars_1, ns)
    time_stars_2 = measure_time (stars_2, ns)

    # plot the results
    import matplotlib.pyplot as plt 
    plt.plot(ns, time_stars_1[1], label = 'stars_1')
    plt.plot(ns, time_stars_2[1], label = 'stars_2')
    plt.xlabel('n')
    plt.ylabel('time')
    plt.title('stars')
    plt.legend()
    plt.show()


if __name__ == "__main__" : 
    stars()
    

