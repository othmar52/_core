#ifndef VOLUME_H
#define VOLUME_H 1

/*
db_startpoint = -36
db_midpoint = -64
db_endpoint = 0
numberOfSteps = 255
cutoff = 160

increment = (db_endpoint - db_startpoint) / (numberOfSteps-1)
increment2 = (db_endpoint - db_midpoint) /  (numberOfSteps-1)

array = [db_startpoint + i * increment for i in range(numberOfSteps)]
array2 = [db_midpoint + i * increment2 for i in range(numberOfSteps)]

def dbamp(v):
    return 10 ** (v / 20)

print(f"#define VOLUME_STEPS {numberOfSteps-1}")
print("const int32_t volume_vals[{}] = {{".format(numberOfSteps))
vals = []
for i, v in enumerate(array):
    if i < cutoff:
        v = (array2[i] * (cutoff - i) / cutoff) + (v * i / cutoff)
    value = round(65535 * dbamp(v) )
    vals.append(value)

vals[0] = 0
vals[1] = 0
for i,v in enumerate(vals):
    if i>=2 and i<=5:
        vals[i] = round(v/(2**(5-i)))
for i,v in enumerate(vals):
    if i<len(vals)-1:
        print(f"{v},", end=" ")
    else:
        print(f"{v}", end=" ")
print("};")
*/
#define VOLUME_STEPS 254
const int32_t volume_vals[255] = {
    0,     0,     6,     12,    25,    53,    55,    58,    61,    64,    67,
    70,    74,    77,    81,    85,    89,    93,    98,    102,   107,   112,
    117,   123,   129,   134,   141,   147,   154,   161,   168,   176,   184,
    192,   201,   210,   219,   229,   239,   249,   260,   272,   283,   296,
    308,   322,   335,   350,   365,   380,   396,   413,   430,   448,   466,
    486,   506,   527,   548,   570,   593,   617,   642,   668,   694,   722,
    751,   780,   811,   842,   875,   909,   944,   980,   1018,  1056,  1096,
    1138,  1180,  1225,  1270,  1317,  1366,  1416,  1468,  1521,  1576,  1633,
    1692,  1752,  1815,  1879,  1945,  2013,  2084,  2156,  2231,  2307,  2387,
    2468,  2552,  2638,  2727,  2818,  2911,  3008,  3107,  3209,  3314,  3421,
    3532,  3645,  3762,  3881,  4004,  4130,  4259,  4392,  4528,  4668,  4811,
    4958,  5108,  5262,  5420,  5582,  5747,  5917,  6091,  6268,  6450,  6637,
    6827,  7022,  7221,  7425,  7633,  7846,  8063,  8286,  8512,  8744,  8981,
    9223,  9469,  9721,  9978,  10240, 10507, 10779, 11057, 11340, 11629, 11923,
    12222, 12527, 12838, 13154, 13475, 13803, 14136, 14369, 14605, 14845, 15090,
    15338, 15590, 15847, 16107, 16372, 16642, 16915, 17194, 17477, 17764, 18056,
    18353, 18655, 18962, 19274, 19591, 19914, 20241, 20574, 20913, 21257, 21606,
    21962, 22323, 22690, 23064, 23443, 23829, 24221, 24619, 25024, 25436, 25855,
    26280, 26712, 27152, 27598, 28052, 28514, 28983, 29460, 29944, 30437, 30938,
    31447, 31964, 32490, 33024, 33568, 34120, 34681, 35252, 35832, 36421, 37020,
    37629, 38249, 38878, 39517, 40168, 40828, 41500, 42183, 42877, 43582, 44299,
    45028, 45769, 46522, 47287, 48065, 48856, 49659, 50476, 51307, 52151, 53009,
    53881, 54767, 55668, 56584, 57515, 58461, 59423, 60400, 61394, 62404, 63431,
    64474, 65535};

#endif