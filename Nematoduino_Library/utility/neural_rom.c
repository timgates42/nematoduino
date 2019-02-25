// Word 0: Number of connected neurons (N_MAX)
// Word 1-(N_MAX): A address (offset from beginning) of each list of connections
// Word N_MAX+1: N_MAX plus the number of connections in the final neuron
// Word > (N_MAX+1): List of connections

// Connection words are formatted as follows:
// Bit 0-7: Lower part of neuron index
// Bit 8: High part of neuron index (9-bits reserved for index)
// Bit 9-15: Weight of connection

#include "neural_rom.h"

const uint16_t NEURAL_ROM[] = {
0x012b, 0x012d, 0x0140, 0x0151, 0x016e, 0x0182, 0x018a, 0x0198, 0x01aa, 0x01ba, 0x01be, 0x01c2, 0x01d1, 0x01de, 0x01ef, 
0x0201, 0x0212, 0x021f, 0x0228, 0x0235, 0x023e, 0x0246, 0x0255, 0x0264, 0x026a, 0x0276, 0x027d, 0x0280, 0x0286, 0x0299, 
0x02a3, 0x02a9, 0x02b4, 0x02bd, 0x02c9, 0x02d0, 0x02d9, 0x02e3, 0x02eb, 0x02f1, 0x02f8, 0x0301, 0x030c, 0x0311, 0x0316, 
0x0326, 0x0337, 0x0341, 0x0349, 0x034e, 0x0352, 0x0358, 0x0361, 0x0369, 0x0372, 0x03a5, 0x03de, 0x0408, 0x0430, 0x0447, 
0x0463, 0x0478, 0x0490, 0x04a1, 0x04b0, 0x04c3, 0x04d5, 0x04e5, 0x04f6, 0x0502, 0x051e, 0x0531, 0x0542, 0x0553, 0x055c, 
0x0569, 0x0572, 0x057e, 0x0587, 0x058e, 0x0599, 0x05a1, 0x05a9, 0x05b4, 0x05c6, 0x05db, 0x05e9, 0x05f9, 0x0603, 0x0615, 
0x0622, 0x0631, 0x063d, 0x064c, 0x0653, 0x065b, 0x066b, 0x067f, 0x0690, 0x06a4, 0x06b2, 0x06bb, 0x06c4, 0x06d1, 0x06de, 
0x06e9, 0x06f1, 0x06fa, 0x0703, 0x070d, 0x0732, 0x073d, 0x0751, 0x075e, 0x076d, 0x077f, 0x0799, 0x079e, 0x07a3, 0x07a6, 
0x07a9, 0x07ac, 0x07b0, 0x07b5, 0x07bc, 0x07c9, 0x07d1, 0x07df, 0x07f0, 0x07f8, 0x0801, 0x0809, 0x0812, 0x081f, 0x082c, 
0x0837, 0x0841, 0x084b, 0x0855, 0x0859, 0x085f, 0x0866, 0x0872, 0x087f, 0x0888, 0x088e, 0x0896, 0x089c, 0x08a6, 0x08b0, 
0x08c0, 0x08d0, 0x08d8, 0x08e3, 0x08f0, 0x08fc, 0x0902, 0x0907, 0x090f, 0x0917, 0x0921, 0x092a, 0x0930, 0x093b, 0x0943, 
0x094a, 0x094e, 0x095b, 0x095d, 0x095f, 0x0967, 0x0989, 0x09af, 0x09b5, 0x09bc, 0x09c4, 0x09d9, 0x09f1, 0x0a05, 0x0a1b, 
0x0a22, 0x0a33, 0x0a4d, 0x0a5d, 0x0a62, 0x0a67, 0x0a76, 0x0a88, 0x0aa0, 0x0ab8, 0x0ac7, 0x0ad1, 0x0ae0, 0x0ae9, 0x0af7, 
0x0b0e, 0x0b1e, 0x0b37, 0x0b4b, 0x0b64, 0x0b67, 0x0b6a, 0x0b79, 0x0b91, 0x0b9e, 0x0bb0, 0x0bbb, 0x0bc8, 0x0bda, 0x0be7, 
0x0bf8, 0x0c0e, 0x0c19, 0x0c1f, 0x0c23, 0x0c30, 0x0c3a, 0x0c3d, 0x0c57, 0x0c6c, 0x0c72, 0x0c79, 0x0c7f, 0x0c87, 0x0c91, 
0x0c97, 0x0c9b, 0x0c9e, 0x0ca1, 0x0cab, 0x0cb8, 0x0cb9, 0x0cba, 0x0cbb, 0x0cbc, 0x0cbe, 0x0cc1, 0x0cc6, 0x0cca, 0x0cd6, 
0x0ce3, 0x0cee, 0x0cf9, 0x0d0b, 0x0d18, 0x0d28, 0x0d35, 0x0d3b, 0x0d44, 0x0d4c, 0x0d55, 0x0d5f, 0x0d6d, 0x0d76, 0x0d82, 
0x0d8a, 0x0d92, 0x0d9f, 0x0daa, 0x0db2, 0x0db8, 0x0dc2, 0x0dd8, 0x0de3, 0x0df2, 0x0dff, 0x0e0a, 0x0e14, 0x0e22, 0x0e34, 
0x0e44, 0x0e59, 0x0e65, 0x0e71, 0x0e87, 0x0e93, 0x0e9e, 0x0ea8, 0x0eb6, 0x0ebc, 0x0eca, 0x0ed9, 0x0ee8, 0x0ef8, 0x0f0e, 
0x0f15, 0x0f1f, 0x0f20, 0x0f2d, 0x0f36, 0x0f3d, 0x0f45, 0x0f51, 0x0f5b, 0x0f64, 0x0f6c, 0x0f74, 0x0f7f, 0x0f86, 0x0f8a, 
0x0f90, 0x2b01, 0x3807, 0x0d02, 0x3b01, 0x3a02, 0x7001, 0x4305, 0x0101, 0x3602, 0xf402, 0xbd01, 0xb201, 0x0401, 0xbc01, 
0xc403, 0x3901, 0xc601, 0x0c01, 0x3704, 0x3805, 0x0d01, 0xc505, 0x3b01, 0xcb01, 0xbc01, 0x0501, 0xc701, 0x3501, 0xf302, 
0x0001, 0x4203, 0x3902, 0xb301, 0x0c01, 0x2c01, 0x3701, 0xea01, 0x9401, 0xca01, 0x4501, 0xce02, 0xee01, 0x7d01, 0xcb01, 
0xda01, 0x0301, 0x3603, 0x3081, 0x3502, 0x0001, 0xc302, 0xbf01, 0x5201, 0xf901, 0x1001, 0xe601, 0x6f01, 0x3b01, 0xc105, 
0xd801, 0x8301, 0x4601, 0x5001, 0xc203, 0xb801, 0xb401, 0xc301, 0xc107, 0x3a02, 0x7001, 0x4301, 0x0101, 0x3601, 0x1601, 
0xdf01, 0x3c01, 0x3505, 0x4401, 0x6f01, 0xcf02, 0x0202, 0x9502, 0x4501, 0xc204, 0x5301, 0x3305, 0x140c, 0xc101, 0x9801, 
0xc802, 0xef02, 0x0001, 0xb80f, 0xb910, 0x1301, 0xc803, 0x0101, 0x0b01, 0x4b01, 0xee01, 0xb101, 0xf002, 0xfc01, 0xc203, 
0x1508, 0x2c01, 0x3404, 0x2b02, 0x0d01, 0x3a04, 0x2803, 0xd801, 0x3603, 0x4a02, 0x1602, 0x3502, 0x0a06, 0x4303, 0x4201, 
0x9801, 0x3901, 0xc601, 0x0c07, 0x0701, 0x3702, 0x3802, 0x0d0a, 0x0601, 0x4d03, 0x3a02, 0x2801, 0x0b0a, 0x3602, 0xa901, 
0xbd01, 0xbc01, 0x4301, 0x3905, 0x9501, 0x2c03, 0x3701, 0x0c01, 0x1207, 0x1101, 0x0901, 0x0801, 0x0d01, 0x130d, 0x2801, 
0x2b01, 0x4d01, 0x2d02, 0x1401, 0x7101, 0x2803, 0xd801, 0x0b01, 0x2901, 0x0e02, 0x0001, 0xbf01, 0x3103, 0x0c0a, 0x4801, 
0x4901, 0x0d0e, 0xc002, 0x2801, 0x0101, 0x4d03, 0x0501, 0x2a01, 0x0a01, 0x2e02, 0x1501, 0x0702, 0x4c01, 0xb501, 0xc50d, 
0x0801, 0xdd02, 0xbb04, 0x6e01, 0xc402, 0x3502, 0xf204, 0xdc02, 0x6f01, 0x2801, 0xc203, 0xbf01, 0xca01, 0x1201, 0x3705, 
0xc501, 0x3803, 0xc103, 0xb501, 0x3b01, 0xcb01, 0x3601, 0xc901, 0x6e02, 0xf103, 0xc410, 0x0d83, 0xf301, 0xdc01, 0xba04, 
0x0901, 0x5f01, 0xb801, 0x3802, 0x3d04, 0x3a01, 0x1701, 0xef01, 0xea01, 0x4201, 0x2902, 0x4002, 0xb201, 0x4101, 0x0a05, 
0x3901, 0x3c01, 0x3102, 0xbf01, 0x3e01, 0x9701, 0xaf01, 0x3d01, 0x7101, 0x3a01, 0x3203, 0x0b05, 0xc001, 0x2a02, 0xd901, 
0x3002, 0x7202, 0x3e01, 0xbb02, 0x1102, 0x0905, 0x2a01, 0xba01, 0x2703, 0x0201, 0x4e03, 0x3401, 0x4f03, 0x3301, 0x2801, 
0x0804, 0x0901, 0x2901, 0xba02, 0x0a02, 0x2701, 0x1002, 0xbe01, 0x0c02, 0x3401, 0x1301, 0x140d, 0x4d01, 0xba04, 0x4c01, 
0xc401, 0x7201, 0xb807, 0x4803, 0x4901, 0xb906, 0x7101, 0xc501, 0xbb02, 0x0501, 0x1508, 0x1201, 0x2b01, 0x0d08, 0xc101, 
0x1081, 0xb808, 0x6c01, 0x2901, 0xef07, 0xc404, 0xed09, 0x0a03, 0x2701, 0x3c05, 0x1502, 0x0c02, 0x4901, 0x0d01, 0x1402, 
0xc504, 0x3b04, 0x0b01, 0x6c01, 0xb907, 0xee05, 0x2a01, 0xf201, 0xf003, 0x3c01, 0x0c08, 0x2c01, 0x3b02, 0xcf01, 0x3c01, 
0x3501, 0x0201, 0xbe01, 0x5203, 0xb401, 0xaa01, 0x3b01, 0x5006, 0xd801, 0x3a01, 0xcd01, 0x4701, 0x5402, 0xe301, 0xa902, 
0xaa03, 0x5501, 0xe501, 0x5105, 0x4701, 0xcc01, 0x5301, 0xf301, 0xee02, 0xde03, 0x0301, 0xdf02, 0xed02, 0xf301, 0xf201, 
0xdb01, 0x4f02, 0x3804, 0xb901, 0xaa02, 0xc102, 0x3a01, 0x4501, 0x3603, 0xb007, 0xb109, 0x3501, 0x4402, 0xfb01, 0x4201, 
0xc201, 0x3901, 0xb803, 0x4e02, 0x3703, 0x3383, 0x1e85, 0x2381, 0x3602, 0x3083, 0x3503, 0x4883, 0x5602, 0x0681, 0x4b84, 
0x3f82, 0x3e83, 0x5782, 0x3601, 0x3501, 0x5683, 0x4181, 0x4281, 0x4081, 0x2282, 0x4381, 0x9b02, 0x9a01, 0x5b81, 0x5881, 
0x5981, 0x5a81, 0x3382, 0x238a, 0x6601, 0x3283, 0x4a83, 0x0782, 0x5701, 0x5f01, 0x4b83, 0x3483, 0x248f, 0x2381, 0x6601, 
0x3601, 0x3583, 0x3502, 0x4d83, 0x5701, 0x5801, 0x0882, 0x4c83, 0x258b, 0x2201, 0x5801, 0x3782, 0x3682, 0x4e83, 0x4f82, 
0x2689, 0x6701, 0x3983, 0x3601, 0x3682, 0x5183, 0x3501, 0x4e82, 0x0a81, 0x3801, 0x5182, 0x3883, 0x3982, 0x3601, 0x0b81, 
0x278d, 0x5a02, 0x3501, 0x5083, 0x3802, 0x3b83, 0x3605, 0x3882, 0x3506, 0x5383, 0x5082, 0x3702, 0x3d83, 0x3a82, 0x3603, 
0x5282, 0x3504, 0x5583, 0x3f83, 0x3c82, 0x3601, 0x3504, 0x6d07, 0x5482, 0x5783, 0x0d02, 0x1306, 0x4d01, 0xb901, 0x0501, 
0x0a03, 0x0c07, 0x120d, 0x4c04, 0x4901, 0x0d0a, 0x130e, 0x0801, 0x0b03, 0x4d01, 0x0a01, 0x0902, 0x0c02, 0x1202, 0x4c01, 
0x1401, 0x0c03, 0x0a09, 0x1101, 0x3101, 0x1001, 0x0d02, 0x0b0a, 0x1501, 0x1301, 0x1401, 0x3a02, 0xb804, 0xd801, 0xbc02, 
0xc601, 0x0403, 0x3502, 0x0001, 0x0a07, 0x3902, 0xc401, 0x3101, 0x0c05, 0x2c01, 0x3706, 0x2b01, 0x3803, 0x0d03, 0x3a01, 
0x3201, 0xbd02, 0x0102, 0x0b0a, 0x3605, 0xb902, 0x0502, 0xb101, 0xd902, 0x3c03, 0x3905, 0x1501, 0x7201, 0x1401, 0x2801, 
0x4d01, 0xba01, 0x1202, 0x0a02, 0x3102, 0x0c01, 0x2e01, 0x4c01, 0x4d01, 0x0d01, 0x2d01, 0x0b02, 0x0a01, 0x2702, 0x2c01, 
0x4c01, 0x3001, 0x3104, 0x7201, 0x7101, 0xb20e, 0x7201, 0xb30d, 0x2f01, 0x3204, 0xb205, 0x3201, 0xd801, 0x0e02, 0x0a0b, 
0x0c02, 0x4901, 0xc001, 0x5501, 0x0b0b, 0x0f01, 0xd901, 0x3101, 0x2c01, 0xb304, 0x1101, 0x3b03, 0x3a01, 0x3503, 0x4a01, 
0xba09, 0xb805, 0x3401, 0x3301, 0xb906, 0x1301, 0x4b01, 0xbb0d, 0x3601, 0x3c04, 0xfc01, 0x1001, 0x6f01, 0x4202, 0xaa05, 
0xa90a, 0x6302, 0x0386, 0x0482, 0x6403, 0xc503, 0x0c87, 0x0285, 0x3605, 0xb001, 0xe201, 0x0b8a, 0x0081, 0x1e04, 0x1d02, 
0x0584, 0x0682, 0x0183, 0x0986, 0x0a82, 0xe004, 0x0885, 0x2002, 0x1f01, 0x1c03, 0x2408, 0x2301, 0x2203, 0x2101, 0x2608, 
0x2505, 0x5907, 0x5a07, 0x5b0b, 0x5c02, 0x5602, 0x5702, 0x5806, 0x5d04, 0x5e03, 0x3801, 0xe401, 0x4001, 0xfd01, 0x0782, 
0x3901, 0x1785, 0x8701, 0x9c01, 0xaa05, 0x0582, 0x6101, 0xa907, 0x6302, 0x9d01, 0x0481, 0x6405, 0x0388, 0x0b8c, 0xc501, 
0x0301, 0x0284, 0xff01, 0xe201, 0xe103, 0x3505, 0x0c86, 0x1e06, 0x1d01, 0x3c02, 0x0685, 0x0983, 0x0a84, 0xe001, 0x0883, 
0x2001, 0x1f02, 0x1c02, 0x2405, 0x2302, 0x2201, 0x2101, 0x2605, 0x2506, 0xfe01, 0x5906, 0x5a05, 0x5b0b, 0x5c03, 0x5606, 
0x5702, 0x5803, 0xc402, 0x5d08, 0x5e02, 0x2282, 0x8803, 0x3b02, 0xc101, 0x3a02, 0x0783, 0x3901, 0x1784, 0x8701, 0x3701, 
0x6c01, 0x6101, 0x6301, 0x6201, 0x6502, 0x6402, 0x3b01, 0x1b01, 0x0281, 0xbb01, 0x3607, 0x3507, 0x1a81, 0xba01, 0x1d01, 
0x3c02, 0xbe01, 0x0a81, 0x2001, 0x2402, 0x2301, 0x2201, 0x2101, 0x2601, 0x0581, 0x3803, 0xaf01, 0xe401, 0x0f82, 0x3a02, 
0xeb01, 0x0e82, 0x4601, 0x1083, 0x0d81, 0x1582, 0x1481, 0x1381, 0x1281, 0x3901, 0x1781, 0x1687, 0x6c01, 0x5f03, 0x6101, 
0x7201, 0x6301, 0x6201, 0x6501, 0x6401, 0x6001, 0x0f81, 0x0e81, 0x6601, 0xbb01, 0x3607, 0x0b81, 0x3506, 0x0c81, 0xba01, 
0x1d01, 0xbe02, 0x0781, 0x2001, 0x1c01, 0x2402, 0x2301, 0x2201, 0x2101, 0x5a01, 0x1f81, 0x2481, 0xeb01, 0x1181, 0x1081, 
0x1582, 0x1482, 0x1281, 0x1786, 0x1683, 0xae02, 0x3703, 0x6f01, 0xa901, 0x0102, 0x3613, 0xe201, 0xe101, 0x350d, 0x1e02, 
0x1d01, 0xe001, 0x0881, 0x1c01, 0x2201, 0x2101, 0x7001, 0x5901, 0x5a01, 0x5601, 0x5701, 0x5804, 0x5d01, 0x4702, 0x8701, 
0x0601, 0x4202, 0x6e01, 0x6201, 0x0381, 0x360f, 0xe201, 0xe103, 0x3510, 0x0002, 0x1d01, 0x0581, 0x0682, 0x0981, 0xe001, 
0x2201, 0x7001, 0x5901, 0x5a02, 0x5602, 0x5701, 0x5801, 0x5d01, 0x5e01, 0xa801, 0x3902, 0x8702, 0x3701, 0x1c01, 0x2381, 
0xaa01, 0xc503, 0xe107, 0xd101, 0x3607, 0x2481, 0xd501, 0xe203, 0x5901, 0xc402, 0x350c, 0x5605, 0x5701, 0x5803, 0x3c01, 
0x0683, 0x0185, 0xe006, 0xb501, 0xd101, 0xd001, 0x6101, 0x3b01, 0x3610, 0xe203, 0xe103, 0x3507, 0x0581, 0x0682, 0x0181, 
0xe002, 0x0881, 0x2001, 0x1f02, 0x1c03, 0xc502, 0xd501, 0x5605, 0x5703, 0x5801, 0xc403, 0x3a01, 0x0781, 0x3802, 0x7101, 
0x6881, 0x6781, 0x4301, 0xb301, 0xb201, 0x4002, 0x9d01, 0x4601, 0x0d81, 0x4103, 0x4201, 0x3f01, 0xae02, 0x3e17, 0x3701, 
0x3805, 0x3d17, 0x2f01, 0x8182, 0x4301, 0x4002, 0xb201, 0x4101, 0x1b81, 0x6a82, 0x4201, 0x3101, 0x7201, 0x2081, 0x3701, 
0x3802, 0xaf01, 0x3d01, 0xb101, 0xb501, 0x3b01, 0x3a01, 0xb301, 0x3603, 0xc001, 0x4601, 0x9e02, 0x4201, 0x3c01, 0xbf01, 
0xa901, 0x5d01, 0x0381, 0x3701, 0x1e81, 0x3801, 0x3d02, 0xf002, 0xc501, 0xb201, 0xa101, 0xc803, 0x4b01, 0xee01, 0x0503, 
0xb102, 0x4101, 0x4203, 0x3901, 0xb302, 0x3e03, 0x3701, 0x3801, 0x0601, 0xc101, 0x3a01, 0x4304, 0x1b02, 0xc804, 0x4001, 
0xb003, 0x3e01, 0xef01, 0x3d03, 0xed01, 0xae01, 0x0702, 0x3702, 0x3804, 0xaf01, 0xa901, 0xaa03, 0x3b01, 0x3a02, 0x4304, 
0xc001, 0x3601, 0x4002, 0xa502, 0x3502, 0xc901, 0x3901, 0x7201, 0x3e01, 0x3701, 0x3801, 0xaa04, 0x3a03, 0xb301, 0x3601, 
0xe101, 0x3501, 0x4204, 0x3c03, 0x3901, 0xa902, 0x3703, 0x9c03, 0x4502, 0x6c01, 0xee01, 0xed01, 0x9d01, 0xb502, 0x0301, 
0x1b02, 0x0d84, 0xb001, 0xb101, 0xd701, 0x3c01, 0xad01, 0xc501, 0xf201, 0xc402, 0x3b02, 0xc101, 0xdd01, 0x0e81, 0xbd01, 
0x4701, 0xbc01, 0xf001, 0xe801, 0x3701, 0xb201, 0xee02, 0xf202, 0xc502, 0x6681, 0xcf01, 0x1b01, 0xd601, 0xb006, 0xc201, 
0x5001, 0xbc01, 0xed01, 0x4402, 0xf001, 0x0201, 0xdc01, 0xc402, 0xf101, 0xe17c, 0x7dfb, 0xe27d, 0x3b7f, 0xb67f, 0x667f, 
0x6b7e, 0x6e09, 0x6d01, 0xb17f, 0x66fb, 0x577f, 0x727f, 0xad01, 0x3e7f, 0xe07b, 0x21fc, 0x3806, 0xb403, 0xaa05, 0x0301, 
0x1701, 0x4301, 0x5102, 0x5003, 0x5601, 0x1801, 0xeb01, 0x0182, 0x3902, 0xbe01, 0xa904, 0xae01, 0x3706, 0x4901, 0x140a, 
0x0805, 0x2901, 0x4a01, 0x0001, 0x0a01, 0x2704, 0x1201, 0x1302, 0x0b01, 0xc002, 0x2802, 0x2701, 0x4b01, 0x0503, 0xc802, 
0x0907, 0xc201, 0x1507, 0x4801, 0x3401, 0x3301, 0x0d01, 0x1409, 0xd801, 0x4b01, 0x0409, 0xed01, 0xb803, 0x3701, 0x3802, 
0xb901, 0xc802, 0xbc01, 0x0504, 0x4a01, 0x2a01, 0xd901, 0xf001, 0x1504, 0x2c02, 0x3401, 0x0d01, 0x4d01, 0xb803, 0x0b04, 
0x3501, 0x0a02, 0x2701, 0x0c01, 0x120a, 0x0d04, 0x1309, 0x0b01, 0x2a01, 0x4c05, 0x2701, 0x1204, 0x4f01, 0xb905, 0xc101, 
0x3b01, 0xc801, 0xbb07, 0x3601, 0xc201, 0xba01, 0x3c04, 0x0c01, 0xc105, 0x3b02, 0xc801, 0x3501, 0xba04, 0xb805, 0x1201, 
0x4e01, 0xaf7e, 0x717f, 0x437f, 0xf57f, 0x407f, 0xdc7f, 0x027d, 0xae7e, 0xaf7f, 0xa97f, 0x037f, 0x407f, 0x357d, 0xf67f, 
0x187f, 0x427e, 0xe37f, 0x727c, 0xae7e, 0x7b04, 0xfd02, 0xee01, 0x9402, 0xf904, 0xd804, 0xf502, 0xbd02, 0xc901, 0xd003, 
0xc602, 0xbc01, 0xe601, 0xba02, 0xc301, 0x3c05, 0xdb04, 0x9606, 0x9705, 0xda04, 0xee01, 0x3b06, 0xd102, 0x7e01, 0xbb01, 
0xbd03, 0xc901, 0xe501, 0x5101, 0xbc04, 0xd901, 0xf601, 0xc301, 0xcc01, 0xfa02, 0x9508, 0xdb01, 0xfe01, 0x7c05, 0x0601, 
0x9404, 0xe701, 0x9806, 0xbd04, 0xc601, 0x5f81, 0xbc07, 0xda01, 0xcc04, 0xc301, 0x7f02, 0x3c03, 0xf702, 0xf801, 0xcd02, 
0x3b05, 0x7781, 0x8001, 0xbd02, 0x8602, 0xc701, 0xbc02, 0x2a01, 0xc301, 0x9903, 0xe802, 0x9507, 0xca01, 0xdb02, 0x3388, 
0x1e91, 0x2381, 0x6604, 0x3606, 0xe203, 0x5901, 0xe102, 0x3502, 0x4b88, 0x2001, 0x1f01, 0x2485, 0x0182, 0x3482, 0x6601, 
0x3602, 0xe101, 0x3282, 0x4a82, 0x3502, 0x3381, 0x4d82, 0x238b, 0x3582, 0x1e82, 0x4b82, 0x4c82, 0x3485, 0x2499, 0x2586, 
0x2101, 0x6701, 0x3602, 0x3785, 0x3585, 0x5902, 0x4d85, 0x4f85, 0x6101, 0x4c85, 0x268f, 0x258c, 0x1481, 0x6701, 0x3985, 
0x3602, 0x3784, 0x3684, 0x5185, 0x3503, 0x4e84, 0x5601, 0x5801, 0x6101, 0x4f84, 0x2681, 0x2302, 0x2790, 0x3605, 0x3984, 
0x3885, 0x5184, 0x3501, 0x5085, 0x6201, 0x0781, 0x0882, 0x2683, 0x2584, 0x2783, 0x3602, 0x3984, 0x3884, 0x3784, 0x3686, 
0x5184, 0x350a, 0x5384, 0x4e84, 0x5084, 0x3b84, 0x4f84, 0x3d84, 0x3c84, 0x3a84, 0x5484, 0x5284, 0x3502, 0x5584, 0x3f84, 
0x3e84, 0x3c84, 0x5784, 0x3601, 0x5484, 0x5684, 0x5e01, 0x4184, 0x4284, 0x4084, 0x2281, 0x4384, 0x3e84, 0x5684, 0x6b01, 
0x9a01, 0xa201, 0x5b84, 0xbe01, 0x5d01, 0x5884, 0x5984, 0x5a84, 0x2001, 0x1f01, 0x0d01, 0x238f, 0x1e95, 0x3803, 0x660a, 
0x6c01, 0x1c01, 0x3281, 0x1181, 0x4a81, 0x3381, 0xc901, 0x1281, 0x2481, 0xbe01, 0x6001, 0x6201, 0x4b81, 0x3801, 0x2497, 
0x2681, 0x258e, 0x3483, 0x6702, 0x4f83, 0x3783, 0x3683, 0x3583, 0x0d82, 0x4e83, 0x4d83, 0x5805, 0x5f01, 0x6106, 0x4c83, 
0x3801, 0x269a, 0x2589, 0x2201, 0x2101, 0x680a, 0x6704, 0x3983, 0x3884, 0x3783, 0x3683, 0x2787, 0x5901, 0x5183, 0x4e83, 
0x5084, 0x4f83, 0x6006, 0x6201, 0x3701, 0x3801, 0x1081, 0x6803, 0x3b82, 0x3982, 0x3882, 0x278d, 0x5182, 0x5382, 0x5082, 
0x1281, 0x5f01, 0x6101, 0x3701, 0x3801, 0x3d82, 0x3c82, 0x3a82, 0x3602, 0x5282, 0x5482, 0x5582, 0x3701, 0x3801, 0x3f82, 
0x3e82, 0x3c82, 0x5782, 0x5482, 0x3503, 0x5682, 0x3702, 0x4182, 0x3801, 0x4082, 0x4382, 0x3e82, 0x4282, 0x2282, 0x5b82, 
0x5a82, 0x5682, 0x5882, 0x5982, 0x3702, 0x33fc, 0x3801, 0x2382, 0x34fb, 0x6701, 0x32fc, 0x4afc, 0x4dfc, 0x577e, 0x35fc, 
0x1e84, 0x4bfc, 0x4cfb, 0x34fc, 0x24ff, 0x2582, 0x6802, 0x6601, 0x4ffc, 0x37fc, 0x36fb, 0x4efb, 0x587f, 0x4cfc, 0x6702, 
0x39fb, 0x38fa, 0x36fb, 0x6901, 0x51fb, 0x4efb, 0x50fa, 0x6801, 0x3bfb, 0x3afb, 0x38fb, 0x52fb, 0x53fb, 0x50fb, 0x2981, 
0x1a81, 0x3ffb, 0x3dfb, 0x3cfb, 0x1f81, 0x2aff, 0x54fb, 0x16ff, 0x57fb, 0x55fb, 0x41fb, 0x42fb, 0x40fb, 0x3efb, 0x43fb, 
0x5bfb, 0x56fb, 0x58fb, 0x59fb, 0x5afb, 0x9c7d, 0xaa7f, 0xc87d, 0xee7e, 0xed7d, 0x5f01, 0x617e, 0x607f, 0x637f, 0x627f, 
0x657f, 0x647e, 0xa97d, 0x3b77, 0x1b7c, 0x367f, 0x357d, 0x04ff, 0x3c7b, 0xe07f, 0x337f, 0x147d, 0xc57f, 0xde7f, 0xdf7f, 
0x05ff, 0xb402, 0x347f, 0x3801, 0xb97f, 0x0ffe, 0xdd7f, 0xef7d, 0x0dff, 0xf07e, 0xb87f, 0x377f, 0xa27f, 0x2607, 0x6b7d, 
0x6e7d, 0x467b, 0x0c81, 0xb07f, 0x2bfb, 0x1781, 0x5d7e, 0x9a7f, 0x1e85, 0xb10d, 0x0d7d, 0xb57f, 0xc17b, 0x0c81, 0x457f, 
0xbb7f, 0x3679, 0xd67e, 0xb002, 0x4609, 0x357b, 0xd77c, 0x447e, 0xba7f, 0xc27b, 0x0c7f, 0x1f84, 0x377f, 0x3805, 0x0d02, 
0x0302, 0x3a0d, 0x7002, 0x6c01, 0x3611, 0x350e, 0xc301, 0x0202, 0x3906, 0x0c01, 0x3704, 0x3801, 0x0d01, 0x3b04, 0x0301, 
0x3a01, 0x4301, 0x3605, 0x0d81, 0x350c, 0x6f02, 0x6c01, 0x3c02, 0x390a, 0xa902, 0x3705, 0x2b01, 0xe102, 0x3d06, 0x1402, 
0x3a02, 0x4b02, 0xc402, 0x4a01, 0x8c87, 0x0a01, 0x4201, 0x3001, 0x3101, 0x1501, 0x7203, 0xbf03, 0x2c02, 0x1c83, 0x0d01, 
0x7101, 0x0c01, 0xc004, 0xe201, 0x1983, 0x1a81, 0x0981, 0xe001, 0x1401, 0x2201, 0x5a01, 0x5b01, 0x8c86, 0x4201, 0x1501, 
0x2b02, 0xaf01, 0x3d01, 0x2582, 0x3a01, 0x5101, 0x4601, 0x4a01, 0xd901, 0xb301, 0xc701, 0x7701, 0xc601, 0x7901, 0x7401, 
0xc701, 0x7301, 0x7701, 0x7901, 0xc601, 0x7301, 0x8902, 0x7401, 0x7301, 0x8902, 0x7401, 0x8a01, 0x8902, 0x8b01, 0x7902, 
0x7605, 0x7505, 0x8902, 0x8f01, 0x7303, 0x8901, 0x5c82, 0x7402, 0x9302, 0x7602, 0x8f02, 0x8e01, 0x7502, 0x9202, 0x7701, 
0xb401, 0x9401, 0xcd01, 0x2c81, 0x2d81, 0x2f82, 0xd501, 0xc602, 0xd004, 0xfd01, 0x7d01, 0xc301, 0x7c01, 0x7b01, 0x7e01, 
0xd105, 0xd501, 0xc705, 0x4583, 0x4484, 0x9501, 0x7b01, 0xcf03, 0x2c83, 0xd401, 0x2e83, 0xcc05, 0x3084, 0x5f83, 0xd004, 
0x5d83, 0x7f01, 0x3c02, 0xd102, 0xce01, 0xda01, 0xcd02, 0x3b01, 0xfc02, 0x8001, 0xce04, 0xd104, 0x7483, 0x7683, 0xcc03, 
0xd001, 0xd302, 0x4683, 0x4483, 0x3c01, 0xcf02, 0x7c01, 0x8001, 0xff01, 0xc604, 0x5e84, 0x5d85, 0x7d01, 0xcc05, 0xd201, 
0xcd0a, 0x7e01, 0x7485, 0x7585, 0xc706, 0x8401, 0x8601, 0x7f01, 0xd401, 0x3301, 0x7b07, 0xd403, 0xf503, 0xc60a, 0xd304, 
0xba01, 0x9602, 0xd402, 0xbd01, 0xd501, 0xc70b, 0xd302, 0xf603, 0x5301, 0xd201, 0x7c07, 0x3b01, 0x9808, 0xd402, 0xd502, 
0xbc01, 0x7d01, 0xfb02, 0xc307, 0xce03, 0x0202, 0xcf01, 0xd801, 0x9605, 0x9702, 0xfa01, 0x0301, 0x8001, 0x7e01, 0xce01, 
0xd501, 0xd302, 0xc306, 0x9907, 0xfc01, 0xd901, 0x9501, 0x4f01, 0xf703, 0x9801, 0xd404, 0x8301, 0xd501, 0xc60b, 0xd301, 
0xc302, 0x7f07, 0xb801, 0xb902, 0x8006, 0xd402, 0xfc01, 0xd503, 0xc70f, 0xd303, 0xc303, 0x9901, 0xf804, 0xa401, 0x3a02, 
0xb601, 0x3606, 0x3505, 0xb401, 0xa001, 0x4201, 0x3904, 0xae01, 0xb401, 0xaa03, 0x3a03, 0x4301, 0xb601, 0x3607, 0xa801, 
0x3503, 0x3901, 0xa501, 0x7602, 0x7502, 0x7701, 0x7801, 0x7702, 0x5c82, 0x8b01, 0x7403, 0x8f01, 0x7303, 0x7702, 0x5c82, 
0x8d01, 0x7403, 0x8f01, 0x7303, 0x8c01, 0x8d01, 0x9303, 0x5c81, 0x7903, 0x7802, 0x7a01, 0x7304, 0x9001, 0x8901, 0x9202, 
0x7404, 0x9101, 0x9001, 0x9303, 0x5c81, 0x7702, 0x7903, 0x7806, 0x7a01, 0x7304, 0x8c01, 0x8901, 0x9202, 0x7404, 0x9101, 
0x8f01, 0x9301, 0x7701, 0x790d, 0x8b01, 0x7a02, 0x8a01, 0x8e06, 0x9201, 0x8f04, 0x7903, 0x8b02, 0x7a01, 0x8a02, 0x8901, 
0x7601, 0x8b02, 0x7403, 0x8a02, 0x7303, 0x8901, 0x7501, 0x7701, 0x7701, 0x8b02, 0x7403, 0x8a02, 0x7303, 0x8901, 0x8d01, 
0x7606, 0x7902, 0x7803, 0x7402, 0x7301, 0x8c01, 0x7506, 0x7a02, 0x7702, 0x8d01, 0x7606, 0x7902, 0x7803, 0x7402, 0x7302, 
0x8c01, 0x7506, 0x7a02, 0x7702, 0x5203, 0xfd01, 0xc101, 0x7b01, 0x5404, 0xf103, 0xf404, 0xcc07, 0xd001, 0xf204, 0xd302, 
0xba08, 0x7f02, 0x3c15, 0x9502, 0xce02, 0xf304, 0x9402, 0x3b10, 0x5506, 0xd402, 0xbb0a, 0xd103, 0xf403, 0xcd0a, 0x8401, 
0xf201, 0x8001, 0xc201, 0x5301, 0xce03, 0x7c02, 0x5201, 0xc101, 0xcd04, 0xf901, 0xeb03, 0xbd01, 0xd001, 0xba02, 0xd101, 
0xbb02, 0xbd01, 0xcc03, 0xbc01, 0xc301, 0xec02, 0xc201, 0xfa01, 0xdb01, 0x5302, 0x0601, 0xc101, 0xf901, 0x5401, 0xd104, 
0xc601, 0x8501, 0xbc01, 0xba01, 0xc301, 0x7f01, 0xcc01, 0xe903, 0xea04, 0xcd01, 0x5501, 0xd401, 0xbb01, 0xbd01, 0xc702, 
0xd004, 0xc302, 0x8001, 0xc201, 0xfa01, 0xaf01, 0x4082, 0x6b01, 0x1e01, 0x5e01, 0x2283, 0x7281, 0x2282, 0xbe02, 0x1e02, 
0x8881, 0xb402, 0xaa01, 0x2081, 0x6c18, 0x0c81, 0x4406, 0xad02, 0x9d03, 0x9c03, 0xaa01, 0x2a81, 0x6c23, 0x0b81, 0x4410, 
0xa901, 0xad01, 0xb202, 0x3d03, 0x3a01, 0xa105, 0x6c02, 0x4001, 0x9f05, 0x4101, 0xa005, 0x3f05, 0xb202, 0x4101, 0xa105, 
0x6c01, 0xb003, 0x9e06, 0xa001, 0x3f03, 0x5d01, 0xa103, 0x3606, 0x3509, 0x3901, 0xa90d, 0x0481, 0x3d01, 0xaa03, 0x3a01, 
0x3607, 0x4001, 0x3507, 0xa003, 0x3901, 0xa906, 0x5d01, 0x0482, 0xa401, 0x6c06, 0x3501, 0x0482, 0xa301, 0xa902, 0x5e07, 
0x8701, 0x8801, 0xaa08, 0xa201, 0x6c08, 0x4101, 0x5e02, 0x0481, 0xa201, 0xa901, 0x7101, 0x8701, 0x8801, 0x9c02, 0x2301, 
0x3a04, 0x6c05, 0x3601, 0xa902, 0x3504, 0xb402, 0x3901, 0x7201, 0x9d03, 0xaa01, 0xdc05, 0xef06, 0xdd04, 0xf006, 0x8801, 
0x3a06, 0x360b, 0xb004, 0x3508, 0x3907, 0x3f01, 0xae01, 0xaa05, 0x6c04, 0x6104, 0x6003, 0x6302, 0x6203, 0x6503, 0x6402, 
0x3b02, 0x0e82, 0x3604, 0xc902, 0x3502, 0x3c01, 0xbe05, 0x1c01, 0x4301, 0x5a01, 0x5b01, 0x5701, 0x4203, 0x380c, 0xa401, 
0x0f81, 0x3a02, 0xeb02, 0x1181, 0x1482, 0x1381, 0x1281, 0x3905, 0x1782, 0x1681, 0x3705, 0x9c01, 0xa301, 0x6103, 0x6001, 
0x6301, 0x6204, 0x6501, 0x6402, 0xa905, 0x3b01, 0x1b01, 0x3607, 0x0b82, 0x3507, 0x0c81, 0x3c01, 0xbe05, 0x1f01, 0x1283, 
0x0e81, 0xb401, 0x6f01, 0x4203, 0xb701, 0x5e01, 0x8801, 0x3806, 0x3a01, 0xab01, 0xb602, 0x4601, 0x1583, 0x1482, 0xec02, 
0x3905, 0x1681, 0xa501, 0x3708, 0xaa06, 0x3606, 0x6a01, 0x3506, 0xa901, 0x1f81, 0xaa0a, 0x3609, 0xab01, 0x6c03, 0x3506, 
0x0c81, 0xa90d, 0x9c07, 0x6c03, 0x4601, 0x4701, 0xb401, 0x440b, 0xa902, 0x9d08, 0x3802, 0xaf05, 0x6583, 0xb501, 0x3b01, 
0x3a03, 0x4305, 0x6602, 0xb601, 0xa901, 0xa801, 0x5102, 0x4602, 0x5001, 0x3502, 0x4205, 0x3903, 0x3f01, 0xbf01, 0x3e01, 
0xb301, 0x2781, 0xa901, 0x7201, 0xb502, 0x3b03, 0x6801, 0x6982, 0x1981, 0x1a81, 0x4301, 0x4204, 0x2181, 0x3802, 0x3502, 
0x2881, 0x3a01, 0xb602, 0x5102, 0x4602, 0x5001, 0xa802, 0x6881, 0xae01, 0x3701, 0x3806, 0x2481, 0xaa03, 0xa804, 0xc102, 
0x1b07, 0x4506, 0x3a02, 0x3601, 0x9f03, 0x6e02, 0xb101, 0x3501, 0x4101, 0x0001, 0xb501, 0x3c01, 0x4401, 0x2282, 0x3705, 
0xaa07, 0x6e0d, 0x4401, 0xa904, 0x1b09, 0x6701, 0x3602, 0xb001, 0x3501, 0xc501, 0x3805, 0xb902, 0x2681, 0x2581, 0x4003, 
0x0501, 0x4604, 0xd901, 0xc201, 0x3704, 0x2c01, 0xb301, 0x7102, 0x2f01, 0xd801, 0x0001, 0x0a03, 0x3105, 0xb302, 0x1e81, 
0x4902, 0x3d01, 0xb501, 0x3204, 0x2801, 0x0101, 0x0b07, 0xb202, 0xc001, 0x6e01, 0x4601, 0x6601, 0x7201, 0xae01, 0x3e01, 
0x3701, 0x7b01, 0x9c01, 0xaa01, 0x4203, 0x6c02, 0xc603, 0xc703, 0x4401, 0x6101, 0x6001, 0x9d01, 0x7c01, 0x0001, 0x4302, 
0xe001, 0xf501, 0x2301, 0x8001, 0x7f01, 0x5e01, 0x8801, 0x3804, 0x1701, 0xa502, 0x8701, 0x3704, 0xd501, 0x0d04, 0xc102, 
0x4507, 0xbb01, 0xd602, 0x6e02, 0xee01, 0x4602, 0xd703, 0x4407, 0xb001, 0xc301, 0xc203, 0x0c02, 0xba01, 0xb701, 0xb502, 
0xaa02, 0x0481, 0x4201, 0xb501, 0x3601, 0xaa01, 0x0481, 0x3a01, 0xb97f, 0xcf7a, 0xcd79, 0xca7e, 0x547f, 0xd175, 0xf178, 
0xf475, 0xd077, 0xf276, 0xf37a, 0xcb7c, 0xcc74, 0xce7a, 0xe57e, 0xf479, 0xcf78, 0xe77f, 0xcd75, 0x557f, 0x7e7f, 0xce7d, 
0xd176, 0xe67f, 0xf179, 0xd074, 0xf279, 0xf373, 0xca7f, 0xcc76, 0xb87c, 0xdd7f, 0xe57f, 0x0d02, 0x9801, 0xf402, 0xed01, 
0xe901, 0xb501, 0x3b01, 0xbb03, 0xe501, 0x3501, 0xba01, 0x3c05, 0x9602, 0x3301, 0x4f01, 0x3801, 0xe701, 0xc101, 0x3a01, 
0xeb01, 0xf101, 0xec01, 0xb803, 0x3701, 0xea01, 0xee01, 0xf302, 0x9901, 0x0c01, 0x9702, 0xb501, 0x3b03, 0xbb01, 0x3602, 
0xe601, 0xba03, 0xc301, 0x3c01, 0xc201, 0x1501, 0x3801, 0xb902, 0xf101, 0xf201, 0xec01, 0xe801, 0x4e01, 0x3701, 0x2b02, 
0xf203, 0xc503, 0x4b01, 0x0101, 0x3606, 0xf103, 0xf401, 0x3505, 0xd701, 0x4401, 0xcb01, 0xc401, 0xed02, 0x4501, 0xf401, 
0xf302, 0x0101, 0x3605, 0xee01, 0xf104, 0x3505, 0xf203, 0x4401, 0x2c02, 0x1f7f, 0x40fe, 0x26ff, 0x9b02, 0x3802, 0x687d, 
0x677c, 0x667c, 0x39ff, 0x1601, 0x5b7d, 0x5f01, 0x5e01, 0x22ff, 0x3701, 0x1e81, 0x3801, 0x1702, 0x4302, 0xb003, 0x4101, 
0xc404, 0x3f01, 0x370a, 0x7201, 0x3811, 0x3d01, 0xaa01, 0xc504, 0x4302, 0xa901, 0x4001, 0xb104, 0xc701, 0x4201, 0x3f01, 
0x2c02, 0x3701, 0x0d03, 0x9401, 0x9801, 0x4502, 0x6e01, 0xff01, 0x4401, 0x1901, 0x3b01, 0x1b02, 0xc802, 0xd601, 0xba01, 
0x3c01, 0xdb03, 0x9601, 0x1e82, 0xfd01, 0xd301, 0x1501, 0x4f01, 0x1081, 0xc203, 0x9701, 0xda04, 0xc103, 0x1b01, 0x4501, 
0xbb01, 0xc801, 0xfe01, 0x0081, 0x4404, 0x9901, 0x3c02, 0x9501, 0x0c03, 0x4e01, 0x1a01, 0x5501, 0x5401, 0xc605, 0xc703, 
0x9906, 0x9702, 0xbb04, 0x0081, 0xba05, 0x9801, 0x3401, 0x9602, 0x5201, 0x1404, 0xd402, 0xd501, 0x6f01, 0x1504, 0x5301, 
0x4f01, 0xb908, 0x8302, 0x0501, 0x8401, 0xb80b, 0x3803, 0x0d01, 0xf301, 0x3b02, 0xd701, 0x7882, 0xdd01, 0x3602, 0xc901, 
0xde03, 0xdf02, 0x3501, 0x4882, 0xf205, 0xba01, 0xce01, 0x3c03, 0xcf01, 0x1201, 0x3702, 0x1301, 0xcf01, 0xd601, 0x4401, 
0xce03, 0x0c04, 0x3b03, 0x0101, 0xbb01, 0x3601, 0x3081, 0x3281, 0x3503, 0xd701, 0x6381, 0x6181, 0x3c02, 0xde03, 0xdf03, 
0x4201, 0x3805, 0xf102, 0xf204, 0xc901, 0x3702, 0x9701, 0xd201, 0x9601, 0x9701, 0xd201, 0x9601, 0x4f01, 0x3301, 0xb901, 
0x1403, 0x7101, 0xc101, 0x6c02, 0xfc01, 0x4b01, 0xb001, 0xfb05, 0x0901, 0x1505, 0xb805, 0x4e01, 0x0d01, 0xcf7c, 0x457c, 
0xce7e, 0xf47f, 0xc47f, 0xf301, 0x447f, 0x547e, 0x5f01, 0x957f, 0x3b79, 0xbb7b, 0x00ff, 0xba7d, 0x557f, 0x3c79, 0xc57c, 
0x4201, 0xcc7f, 0x537f, 0xf101, 0x467e, 0xf27e, 0xb97f, 0x7bfe, 0x78ff, 0x79ff, 0xce7e, 0xb87f, 0xf27f, 0xf301, 0xcb02, 
0xe87e, 0xe402, 0x0c01, 0xdd7d, 0xf402, 0x0d01, 0xcf7f, 0xe77e, 0x77ff, 0xca02, 0x79ff, 0xd17f, 0xb97f, 0xd57f, 0xf17e, 
0xe402, 0x62ff, 0x61ff, 0xcc7f, 0xdc7e, 0x64ff, 0xb87e, 0x9801, 0xce01, 0xd107, 0x7481, 0xd001, 0xf101, 0x4781, 0x4581, 
0x4681, 0x4481, 0x4b82, 0xfd01, 0x2c81, 0x2d81, 0x2e82, 0x2f81, 0x7481, 0x7581, 0x4781, 0xf201, 0xd00c, 0x9901, 0xd101, 
0xdd01, 0xb903, 0x7a81, 0xcf03, 0xcd01, 0x7882, 0xd401, 0x2e81, 0x3082, 0x7481, 0xcc01, 0xd001, 0x5d81, 0x4681, 0x4481, 
0x9502, 0xd601, 0x7681, 0xb804, 0xb907, 0xc502, 0x2e81, 0xd101, 0x3081, 0xc901, 0x5f81, 0x4881, 0x4401, 0x6181, 0xcc01, 
0xb803, 0xce01, 0x7b81, 0xcd06, 0x7781, 0x7881, 0x7981, 0xce01, 0xd101, 0x7481, 0x7581, 0x7681, 0xcc01, 0xf301, 0xde01, 
0x6081, 0x4481, 0x3c01, 0x9601, 0xea01, 0xcf01, 0xf401, 0xd001, 0x9701, 0x3b01, 0x2c81, 0x5e81, 0x5f81, 0x5d81, 0x6281, 
0x6081, 0x6181, 0x3c01, 0x6481, 0xcd01, 0xdf01, 0xcc04, 0x7b81, 0x7781, 0x7981, 0xec01, 0xd502, 0x77fe, 0xbb7f, 0x75fe, 
0xc601, 0x5efe, 0xc701, 0x62fe, 0xba7f, 0x60fe, 0x7f01, 0xc101, 0x74fd, 0xd501, 0x76fd, 0x46fd, 0x44fd, 0x2cfb, 0x2efb, 
0x5dfb, 0xd501, 0x7b01, 0x3b01, 0x2dff, 0x2fff, 0x31ff, 0x47ff, 0xf27f, 0x45ff, 0x3c01, 0xd301, 0xd202, 0xd401, 0x7c01, 
0xb501, 0xcf03, 0x4504, 0x7481, 0x7681, 0x4404, 0x4681, 0xfa01, 0xc201, 0xd901, 0x4503, 0x4403, 0xce02, 0x0d01, 0x0601, 
0xcf03, 0xef01, 0xd003, 0xfb01, 0xce01, 0x1901, 0xda03, 0x3b02, 0x3082, 0x3501, 0x0001, 0x6182, 0x3101, 0xbe01, 0xdb01, 
0x5201, 0x2b01, 0x3802, 0xe701, 0x1701, 0xeb02, 0x8301, 0x4a01, 0xec01, 0x3801, 0x7a81, 0xcf02, 0x3201, 0x4b01, 0x0101, 
0x4881, 0x3601, 0x0f01, 0xc801, 0x8401, 0xfc01, 0x7881, 0x4201, 0x3c03, 0x3901, 0xd105, 0xce04, 0xdb01, 0x2c01, 0x1a01, 
0xcf01, 0xd803, 0x4482, 0x7482, 0x4683, 0xec01, 0x2c82, 0xd801, 0x2e82, 0x3082, 0x5d82, 0xd901, 0xd401, 0xc506, 0x3506, 
0xed01, 0xd901, 0xc403, 0x0c01, 0xc505, 0x0d01, 0x9401, 0xcd01, 0xd801, 0x3603, 0xd601, 0xc404, 0x1901, 0xc50c, 0xd001, 
0x3511, 0xd702, 0xf208, 0xf003, 0xc402, 0x9501, 0x0c01, 0xc502, 0x360d, 0xd101, 0xef02, 0xf106, 0xc405, 0x0583, 0x0682, 
0x3504, 0x0781, 0x3603, 0x5602, 0x5701, 0x3501, 0x3601, 0x5603, 0x0d01, 0xe401, 0x3b01, 0x1701, 0xbd01, 0x3603, 0xc903, 
0xd601, 0x3501, 0x6f01, 0x3804, 0x0601, 0xeb01, 0xbd01, 0xcb02, 0x6c03, 0x3502, 0xda02, 0xca02, 0xe301, 0x0c02, 0xdb01, 
0x3706, 0xba01, 0xbb01, 0xba01, 0xbb01, 0xeb01, 0xba01, 0x0e01, 0xbb01, 0xec01, 0x3801, 0xe901, 0xe401, 0xba01, 0x3701, 
0xea01, 0xbb01, 0xda01, 0xba01, 0xdf01, 0x4501, 0x3601, 0x4983, 0x4782, 0x4401, 0x4682, 0x4482, 0x4582, 0xdc01, 0xd203, 
0xba01, 0x1901, 0xbb01, 0x4502, 0x2e81, 0x2f81, 0x4781, 0x3182, 0x3501, 0x4401, 0xde03, 0xd204, 0x2d81, 0x4b81, 0xdf02, 
0xa601, 0xd505, 0x5e81, 0x5f81, 0x5d81, 0x6281, 0x6081, 0x6181, 0xdc03, 0x6481, 0x7781, 0xdd04, 0x4501, 0x7a81, 0x7481, 
0x7581, 0x7681, 0x4401, 0xd503, 0xde03, 0x7981, 0x3381, 0x5e81, 0xb901, 0xbb01, 0x2f81, 0xc901, 0x3181, 0xf402, 0x4981, 
0x4a81, 0x4781, 0x4881, 0x4581, 0x4681, 0x6081, 0xcc01, 0xb801, 0xba01, 0x3381, 0x1e81, 0xb901, 0xcd01, 0xbb01, 0x2f81, 
0x3081, 0x3181, 0xc901, 0x4981, 0x4781, 0x7581, 0xb802, 0xf401, 0xb908, 0xb401, 0xcd01, 0x7781, 0xca01, 0x7981, 0xbb02, 
0xc901, 0x7581, 0x7681, 0x5f81, 0xd001, 0xf204, 0x6281, 0xb803, 0xb905, 0x7a81, 0xd101, 0xf102, 0x5e81, 0x5f81, 0x0d81, 
0xf301, 0xba02, 0x6081, 0xcb02, 0xcc01, 0xb807, 0x7b02, 0x2d82, 0x2e82, 0x2f82, 0xc603, 0xd301, 0xd401, 0xd101, 0xfe01, 
0xc703, 0x4582, 0x4683, 0x4483, 0xd201, 0x7c01, 0xd401, 0xd502, 0xc603, 0x5e82, 0x5f83, 0x5d82, 0xd301, 0x6082, 0x7782, 
0x7e01, 0x7482, 0x7582, 0x7682, 0xc703, 0xd001, 0xd502, 0xd402, 0x5201, 0xe701, 0xcd01, 0x9801, 0xbd01, 0xee01, 0x7d01, 
0xfb02, 0x3701, 0x9601, 0x3801, 0xfc06, 0x9701, 0xcf01, 0x0101, 0xce01, 0xbd01, 0xd601, 0x8401, 0x9901, 0xe802, 0xed01, 
0x7e03, 0x5301, 0x2b01, 0x3305, 0xc103, 0x3b04, 0x4301, 0xd802, 0xbc01, 0xb808, 0x3701, 0x3802, 0xb903, 0xe801, 0xc703, 
0xcf01, 0xc202, 0x8401, 0xd901, 0x9901, 0x3c02, 0x3404, 0x3701, 0xc101, 0xcd04, 0xd006, 0xf101, 0x3501, 0xf201, 0xba01, 
0x3c02, 0x3b02, 0x3601, 0xbb01, 0xcc03, 0xf104, 0xc201, 0x3c02, 0xd105, 0x3801, 0xc101, 0xd102, 0xec01, 0x3601, 0xc901, 
0xf404, 0xcc04, 0xba02, 0xc301, 0x7f01, 0x3c05, 0xb801, 0xea01, 0xb901, 0xcd06, 0x3b06, 0x8001, 0xbb01, 0xd004, 0x3501, 
0xf303, 0xeb01, 0xc201, 0x1e82, 0x7b83, 0x6609, 0x7a83, 0x3503, 0x6383, 0x5702, 0x6483, 0x8485, 0x8585, 0x3601, 0x3501, 
0x6d85, 0x6e85, 0xaf02, 0x8785, 0x0e81, 0x8685, 0x3607, 0x6b0a, 0x7085, 0x3501, 0x6f85, 0x2184, 0xaa03, 0xa902, 0x0381, 
0x6504, 0x0f81, 0x3601, 0x6b02, 0x1e02, 0x7185, 0x7285, 0x7385, 0xa201, 0xa301, 0x5d03, 0x5e05, 0x228b, 0x2183, 0x8b85, 
0x8985, 0x8a85, 0x8885, 0x8702, 0x1e82, 0x7d85, 0x660d, 0x7a85, 0x0d82, 0x6685, 0x3504, 0x2388, 0x6385, 0x0682, 0xe003, 
0x7f85, 0x1c01, 0x7d85, 0x7c85, 0x670b, 0x6612, 0x3602, 0x2483, 0x6685, 0x3501, 0x6885, 0x0781, 0x2383, 0x6585, 0xe002, 
0x1f02, 0x7e86, 0x2583, 0x1182, 0x7f86, 0x6715, 0x3603, 0x6786, 0x5a01, 0x3501, 0x6886, 0x3901, 0xe001, 0x2002, 0x7e85, 
0x2682, 0x8185, 0x680d, 0x6705, 0x3603, 0x6785, 0x5a02, 0x3505, 0x6a85, 0x8085, 0x2681, 0x8185, 0x6818, 0x2782, 0x3602, 
0x6985, 0x3506, 0x6a85, 0x1382, 0x8084, 0x8c84, 0x8284, 0x2201, 0x6803, 0x3604, 0x6984, 0x690c, 0x1181, 0x2889, 0x3502, 
0x6b84, 0x6c84, 0x8384, 0x3801, 0x2301, 0x8286, 0x2985, 0x3604, 0x0b81, 0x6915, 0x2885, 0x350a, 0x0c81, 0x6b86, 0x1481, 
0x6c86, 0xaa02, 0x1783, 0x1683, 0x9d01, 0x8386, 0x3801, 0x1686, 0xaa01, 0x8285, 0x2a8a, 0x8585, 0x6e01, 0x6d01, 0x2881, 
0x3501, 0x6b85, 0x6a0f, 0x6e85, 0x1784, 0x6903, 0xb501, 0x1e83, 0x0d01, 0x0183, 0x7b81, 0x6601, 0x7a81, 0x6c01, 0xd602, 
0xf401, 0x1084, 0x2381, 0x4404, 0x6381, 0x0681, 0xc402, 0xdc09, 0x6481, 0x6002, 0xdd02, 0xe001, 0x3701, 0x3801, 0x2182, 
0xb501, 0x8785, 0x8685, 0x6b09, 0x7085, 0x4401, 0x6f85, 0xa901, 0x2081, 0x3702, 0x3801, 0x8b85, 0x8985, 0x8a85, 0x8885, 
0x6b07, 0xaa01, 0x7185, 0x7285, 0x7385, 0x0481, 0x3702, 0x6201, 0x7f84, 0x7d84, 0x6701, 0x6614, 0x1981, 0x6384, 0x0581, 
0x6584, 0x3801, 0x2483, 0x2389, 0x7c84, 0xc101, 0x7a84, 0x1181, 0x6684, 0x0d84, 0x6884, 0x1582, 0x1381, 0x3703, 0x3801, 
0x7e86, 0x7f86, 0x6725, 0x8186, 0x6786, 0x1081, 0x6886, 0x6a86, 0x5f01, 0x0a81, 0x0781, 0x3801, 0x7e85, 0x8185, 0x6810, 
0x6706, 0x6785, 0x6a85, 0x1381, 0x5f01, 0x6201, 0x3701, 0x8086, 0x8186, 0x681b, 0x2787, 0x1081, 0x6986, 0x1481, 0x6a86, 
0x1281, 0x3701, 0x3802, 0x8c86, 0x8386, 0x8286, 0x2781, 0x691e, 0x5901, 0x2888, 0x0b81, 0x6b86, 0x1381, 0x6c86, 0x1581, 
0x3701, 0x3802, 0x8285, 0x6902, 0x1082, 0x6b85, 0x3702, 0x3803, 0x8485, 0x8785, 0x2a8a, 0x8585, 0x6a1e, 0x0b83, 0x0c89, 
0x6d85, 0x7085, 0x6e85, 0x1783, 0x1f81, 0x3707, 0x3806, 0x1683, 0x8486, 0x8786, 0x3604, 0x0b83, 0x6a08, 0x6d01, 0x3505, 
0x0c84, 0x6d86, 0x7086, 0xa902, 0x1f85, 0x3701, 0x1e81, 0x2481, 0x8c86, 0x2685, 0xb502, 0x2781, 0x6806, 0x6706, 0x6607, 
0x6e01, 0x4602, 0x1986, 0x1a82, 0x2381, 0x2582, 0x1e82, 0x8c8a, 0x2685, 0xaa01, 0x2781, 0x6809, 0x6704, 0x6606, 0x6e01, 
0x1886, 0x1a84, 0xb502, 0x2585, 0x2382, 0x6201, 0xb301, 0x6e01, 0x7201, 0x6805, 0x6704, 0x6602, 0x690c, 0xb101, 0x1882, 
0x1982, 0x1b81, 0x1c82, 0x2481, 0x2381, 0x1e81, 0xaf01, 0x8c8b, 0x2684, 0x2582, 0x2885, 0x2784, 0x4601, 0xb304, 0x8c87, 
0x4101, 0x1881, 0x1a84, 0x1c81, 0x3e01, 0x3701, 0x8c82, 0x7101, 0xf903, 0x6e02, 0x1a82, 0x3d01, 0x1b81, 0x9501, 0x3e01, 
0xb501, 0x8c81, 0x2387, 0x7bfd, 0xc102, 0x78fd, 0x6604, 0x6e05, 0x1881, 0xf201, 0x61fd, 0x0581, 0xbf01, 0x64fd, 0x01fe, 
0x3801, 0x84fa, 0x87fa, 0x2a85, 0x6e04, 0x6a7f, 0x6dfa, 0x70fa, 0x17fe, 0x87fa, 0x0eff, 0x86fa, 0x367e, 0x70fa, 0x6ffa, 
0x03ff, 0x89fd, 0x0fff, 0x0eff, 0x86fd, 0x6ffd, 0x71fd, 0x03fd, 0x04fe, 0x8bfa, 0xa97f, 0x89fa, 0x8afa, 0x88fa, 0x367e, 
0xb002, 0x71fa, 0x72fa, 0x73fa, 0x04ff, 0xaa7f, 0x1e87, 0x1c01, 0x7dfb, 0x10fd, 0x6602, 0x7afb, 0x2482, 0x66fb, 0x63fb, 
0x05fa, 0x7ffb, 0x2382, 0x7cfb, 0xb001, 0x10fe, 0x68fa, 0x06fe, 0x65fb, 0x2581, 0xb101, 0x7efa, 0x2681, 0x7ffa, 0x6702, 
0x2481, 0x67fa, 0x68fa, 0x2581, 0x81f3, 0x2782, 0x367f, 0xb101, 0x6af3, 0x12fe, 0x08fe, 0x80fb, 0x2682, 0x83fb, 0x2881, 
0x81fb, 0x69fb, 0x357f, 0x6afb, 0x13fe, 0x6cfb, 0x09ff, 0x8cfb, 0x83fb, 0x82fb, 0x2781, 0x0c81, 0x6bfb, 0x6cfb, 0x0bfc, 
0x6bf4, 0x82f4, 0x697f, 0x84f9, 0x85f9, 0x1f85, 0x6df9, 0x6ef9, 0x9d01
};
