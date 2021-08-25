#pragma once
#include <stdarg.h>
namespace Eloquent {
    namespace ML {
        namespace Port {
            class RandomForest {
                public:
                    /**
                    * Predict class for features vector
                    */
                    int predict(double *x) {
                        uint8_t votes[2] = { 0 };
                        // tree #1
                        if (x[9] <= 89.25) {
                            if (x[37] <= 203.28500366210938) {
                                if (x[62] <= 20.03499984741211) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[28] <= 163.33999633789062) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }

                            else {
                                if (x[42] <= 239.47000122070312) {
                                    votes[0] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        else {
                            votes[1] += 1;
                        }

                        // tree #2
                        if (x[61] <= 25.71500015258789) {
                            if (x[42] <= 179.7949981689453) {
                                if (x[49] <= 118.70999908447266) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }

                            else {
                                if (x[13] <= 131.8949966430664) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }
                        }

                        else {
                            votes[0] += 1;
                        }

                        // tree #3
                        if (x[11] <= 109.11499786376953) {
                            if (x[25] <= 168.64500427246094) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[9] <= 86.34000015258789) {
                                    votes[0] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        else {
                            if (x[5] <= 43.459999084472656) {
                                votes[1] += 1;
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        // tree #4
                        if (x[4] <= 28.619999885559082) {
                            votes[0] += 1;
                        }

                        else {
                            if (x[22] <= 258.7249984741211) {
                                if (x[21] <= 235.62000274658203) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[28] <= 244.0399932861328) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        // tree #5
                        if (x[6] <= 31.910000801086426) {
                            votes[1] += 1;
                        }

                        else {
                            if (x[62] <= 30.364998817443848) {
                                if (x[1] <= 15.925000190734863) {
                                    if (x[17] <= 152.28500366210938) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    if (x[12] <= 65.6500015258789) {
                                        if (x[50] <= 135.42499923706055) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        // tree #6
                        if (x[17] <= 130.19000244140625) {
                            if (x[4] <= 30.65499973297119) {
                                votes[0] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            if (x[0] <= 12.759999752044678) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[6] <= 58.77499961853027) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }
                        }

                        // tree #7
                        if (x[4] <= 28.619999885559082) {
                            if (x[14] <= 103.9900016784668) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[58] <= 34.81999969482422) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }
                        }

                        else {
                            if (x[7] <= 44.46500015258789) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[39] <= 152.63000106811523) {
                                    votes[0] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        // tree #8
                        if (x[2] <= 24.199999809265137) {
                            if (x[35] <= 201.25499725341797) {
                                votes[0] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            if (x[45] <= 138.43000030517578) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[61] <= 23.085000038146973) {
                                    if (x[49] <= 144.94000244140625) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        // tree #9
                        if (x[31] <= 248.86000061035156) {
                            if (x[30] <= 311.3949890136719) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[50] <= 120.88500213623047) {
                                    votes[0] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        else {
                            if (x[17] <= 156.76499938964844) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[45] <= 194.63500213623047) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }
                        }

                        // tree #10
                        if (x[49] <= 112.04000091552734) {
                            if (x[60] <= 23.90499973297119) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[63] <= 14.000000476837158) {
                                    votes[0] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        else {
                            if (x[32] <= 221.875) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[33] <= 287.01499938964844) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }
                        }

                        // tree #11
                        if (x[47] <= 167.09500122070312) {
                            if (x[9] <= 81.90499877929688) {
                                if (x[3] <= 31.735000610351562) {
                                    if (x[12] <= 109.53499984741211) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[3] <= 19.984999656677246) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            if (x[28] <= 290.7050018310547) {
                                votes[1] += 1;
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        // tree #12
                        if (x[19] <= 151.0300064086914) {
                            votes[0] += 1;
                        }

                        else {
                            if (x[6] <= 47.739999771118164) {
                                if (x[50] <= 145.39500427246094) {
                                    if (x[28] <= 323.75999450683594) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        // tree #13
                        if (x[6] <= 45.97999954223633) {
                            if (x[59] <= 30.539999961853027) {
                                if (x[10] <= 64.76499938964844) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }

                            else {
                                if (x[61] <= 25.225000381469727) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }
                        }

                        else {
                            if (x[21] <= 306.0749969482422) {
                                votes[0] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        // tree #14
                        if (x[54] <= 77.60499954223633) {
                            if (x[55] <= 58.970001220703125) {
                                if (x[40] <= 166.76499938964844) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[41] <= 243.36499786376953) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }

                            else {
                                if (x[48] <= 137.78000259399414) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }
                        }

                        else {
                            votes[0] += 1;
                        }

                        // tree #15
                        if (x[15] <= 136.01000213623047) {
                            if (x[27] <= 232.41000366210938) {
                                if (x[24] <= 251.31999969482422) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            if (x[37] <= 324.0500030517578) {
                                if (x[6] <= 42.46000099182129) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        // tree #16
                        if (x[27] <= 209.0250015258789) {
                            votes[0] += 1;
                        }

                        else {
                            if (x[30] <= 308.9049987792969) {
                                if (x[61] <= 31.28499984741211) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }

                            else {
                                if (x[57] <= 50.30000114440918) {
                                    votes[0] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        // tree #17
                        if (x[3] <= 24.960000038146973) {
                            if (x[62] <= 29.66499900817871) {
                                votes[0] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            if (x[62] <= 14.110000133514404) {
                                votes[0] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        // tree #18
                        if (x[23] <= 160.85499572753906) {
                            votes[0] += 1;
                        }

                        else {
                            if (x[26] <= 216.34500122070312) {
                                if (x[11] <= 101.52000045776367) {
                                    votes[0] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        // tree #19
                        if (x[26] <= 216.34500122070312) {
                            if (x[10] <= 63.744998931884766) {
                                if (x[0] <= 15.239999771118164) {
                                    votes[0] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        else {
                            if (x[4] <= 19.045000076293945) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[30] <= 312.88499450683594) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }
                        }

                        // tree #20
                        if (x[30] <= 308.4100036621094) {
                            if (x[17] <= 130.19000244140625) {
                                if (x[17] <= 97.34500122070312) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            votes[0] += 1;
                        }

                        // return argmax of votes
                        uint8_t classIdx = 0;
                        float maxVotes = votes[0];

                        for (uint8_t i = 1; i < 2; i++) {
                            if (votes[i] > maxVotes) {
                                classIdx = i;
                                maxVotes = votes[i];
                            }
                        }

                        return classIdx;
                    }

                    /**
                    * Predict readable class name
                    */
                    const char* predictLabel(double *x) {
                        return idxToLabel(predict(x));
                    }

                    /**
                    * Convert class idx to readable name
                    */
                    const char* idxToLabel(uint8_t classIdx) {
                        switch (classIdx) {
                            case 0:
                            return "drive";
                            case 1:
                            return "stop";
                            default:
                            return "Houston we have a problem";
                        }
                    }

                protected:
                };
            }
        }
    }