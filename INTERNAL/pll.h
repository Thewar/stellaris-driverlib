/* 
* pll.h
*
* Giovanni Cimolin da Silva
* 
* 12.08.2014
*/

void pll_init(void);
void set_cpu_freq(char sysdiv ,char lsb);
unsigned long get_cpu_freq(void);

/*
SYSDIV    LSB     Divisor    Clock (MHz)
 0        0        1         reserved 
 0        1        2         reserved
 1        0        3         reserved
 1        1        4         reserved
 2        0        5         80.000
 2        1        6         66.667
 3        0        7         reserved
 3        1        8         50.000
 4        0        9         44.444
 4        1        10        40.000
 5        0        11        36.364
 5        1        12        33.333
 6        0        13        30.769
 6        1        14        28.571
 7        0        15        26.667
 7        1        16        25.000
 8        0        17        23.529
 8        1        18        22.222
 9        0        19        21.053
 9        1        20        20.000
10        0        21        19.048
10        1        22        18.182
11        0        23        17.391
11        1        24        16.667
12        0        25        16.000
12        1        26        15.385
13        0        27        14.815
13        1        28        14.286
14        0        29        13.793
14        1        30        13.333
15        0        31        12.903
15        1        32        12.500
16        0        33        12.121
16        1        34        11.765
17        0        35        11.429
17        1        36        11.111
18        0        37        10.811
18        1        38        10.526
19        0        39        10.256
19        1        40        10.000
20        0        41        9.756
20        1        42        9.524
21        0        43        9.302
21        1        44        9.091
22        0        45        8.889
22        1        46        8.696
23        0        47        8.511
23        1        48        8.333
24        0        49        8.163
24        1        50        8.000
25        0        51        7.843
25        1        52        7.692
26        0        53        7.547
26        1        54        7.407
27        0        55        7.273
27        1        56        7.143
28        0        57        7.018
28        1        58        6.897
29        0        59        6.780
29        1        60        6.667
30        0        61        6.557
30        1        62        6.452
31        0        63        6.349
31        1        64        6.250
32        0        65        6.154
32        1        66        6.061
33        0        67        5.970
33        1        68        5.882
34        0        69        5.797
34        1        70        5.714
35        0        71        5.634
35        1        72        5.556
36        0        73        5.479
36        1        74        5.405
37        0        75        5.333
37        1        76        5.263
38        0        77        5.195
38        1        78        5.128
39        0        79        5.063
39        1        80        5.000
40        0        81        4.938
40        1        82        4.878
41        0        83        4.819
41        1        84        4.762
42        0        85        4.706
42        1        86        4.651
43        0        87        4.598
43        1        88        4.545
44        0        89        4.494
44        1        90        4.444
45        0        91        4.396
45        1        92        4.348
46        0        93        4.301
46        1        94        4.255
47        0        95        4.211
47        1        96        4.167
48        0        97        4.124
48        1        98        4.082
49        0        99        4.040
49        1        100       4.000
50        0        101       3.960
50        1        102       3.922
51        0        103       3.883
51        1        104       3.846
52        0        105       3.810
52        1        106       3.774
53        0        107       3.738
53        1        108       3.704
54        0        109       3.670
54        1        110       3.636
55        0        111       3.604
55        1        112       3.571
56        0        113       3.540
56        1        114       3.509
57        0        115       3.478
57        1        116       3.448
58        0        117       3.419
58        1        118       3.390
59        0        119       3.361
59        1        120       3.333
60        0        121       3.306
60        1        122       3.279
61        0        123       3.252
61        1        124       3.226
62        0        125       3.200
62        1        126       3.175
63        0        127       3.150
63        1        128       3.125

*/
