#pragma once
//#include <cstdarg>
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
                        if (x[56] <= 52.345001220703125) {
                            if (x[22] <= 250.64500427246094) {
                                if (x[58] <= 21.559999465942383) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[63] <= 14.679999828338623) {
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

                        else {
                            votes[0] += 1;
                        }

                        // tree #2
                        if (x[57] <= 44.21999931335449) {
                            if (x[62] <= 15.799999713897705) {
                                votes[1] += 1;
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        else {
                            if (x[44] <= 204.23500061035156) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[18] <= 208.76499938964844) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }
                        }

                        // tree #3
                        if (x[54] <= 66.08499908447266) {
                            votes[1] += 1;
                        }

                        else {
                            if (x[17] <= 193.48999786376953) {
                                if (x[53] <= 60.40999794006348) {
                                    if (x[51] <= 103.39999771118164) {
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
                                if (x[61] <= 23.6200008392334) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }
                        }

                        // tree #4
                        if (x[1] <= 24.645000457763672) {
                            if (x[54] <= 66.72000122070312) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[7] <= 72.32500076293945) {
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

                        // tree #5
                        if (x[20] <= 224.2249984741211) {
                            if (x[51] <= 89.82499694824219) {
                                if (x[16] <= 140.3499984741211) {
                                    votes[0] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                if (x[17] <= 138.25) {
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

                        // tree #6
                        if (x[5] <= 37.27000045776367) {
                            if (x[61] <= 29.68000030517578) {
                                votes[1] += 1;
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        else {
                            if (x[6] <= 43.34000015258789) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[3] <= 29.174999237060547) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }
                        }

                        // tree #7
                        if (x[16] <= 119.3900032043457) {
                            if (x[1] <= 15.880000591278076) {
                                votes[1] += 1;
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        else {
                            if (x[61] <= 25.980000495910645) {
                                if (x[62] <= 33.529998779296875) {
                                    if (x[26] <= 218.67499542236328) {
                                        if (x[39] <= 225.8800048828125) {
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

                                else {
                                    votes[0] += 1;
                                }
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        // tree #8
                        if (x[54] <= 66.08499908447266) {
                            if (x[43] <= 155.31500244140625) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[52] <= 99.36999893188477) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[22] <= 195.65999603271484) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }
                        }

                        else {
                            if (x[29] <= 307.06500244140625) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[1] <= 17.69000005722046) {
                                    votes[0] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        // tree #9
                        if (x[43] <= 163.34000396728516) {
                            votes[0] += 1;
                        }

                        else {
                            if (x[2] <= 18.9399995803833) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[54] <= 79.375) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }
                        }

                        // tree #10
                        if (x[4] <= 27.520000457763672) {
                            if (x[6] <= 43.420000076293945) {
                                votes[0] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            if (x[27] <= 230.0199966430664) {
                                votes[0] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        // tree #11
                        if (x[6] <= 42.6200008392334) {
                            if (x[40] <= 247.82500457763672) {
                                if (x[32] <= 236.86499786376953) {
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
                            if (x[33] <= 226.83000946044922) {
                                if (x[15] <= 131.96499633789062) {
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

                        // tree #12
                        if (x[50] <= 115.48500061035156) {
                            if (x[50] <= 76.64500045776367) {
                                votes[0] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            if (x[33] <= 280.05499267578125) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[10] <= 55.18000030517578) {
                                    votes[0] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        // tree #13
                        if (x[43] <= 157.87000274658203) {
                            votes[0] += 1;
                        }

                        else {
                            if (x[17] <= 138.25) {
                                if (x[2] <= 26.600000381469727) {
                                    votes[0] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                if (x[34] <= 297.7050018310547) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }
                        }

                        // tree #14
                        if (x[5] <= 33.66499900817871) {
                            if (x[53] <= 82.625) {
                                votes[1] += 1;
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        else {
                            if (x[2] <= 28.655000686645508) {
                                if (x[10] <= 50.10000038146973) {
                                    if (x[3] <= 31.035000801086426) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    if (x[55] <= 42.119998931884766) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        if (x[36] <= 269.6300048828125) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[11] <= 107.79000091552734) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        // tree #15
                        if (x[27] <= 228.58499908447266) {
                            votes[0] += 1;
                        }

                        else {
                            if (x[54] <= 81.2750015258789) {
                                if (x[35] <= 278.06500244140625) {
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

                        // tree #16
                        if (x[43] <= 166.62000274658203) {
                            if (x[47] <= 153.03499603271484) {
                                votes[0] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            if (x[4] <= 26.300000190734863) {
                                if (x[22] <= 177.47000122070312) {
                                    votes[0] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                if (x[0] <= 19.800000190734863) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[55] <= 43.65500068664551) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }
                        }

                        // tree #17
                        if (x[7] <= 66.32500076293945) {
                            if (x[7] <= 45.68499946594238) {
                                if (x[25] <= 158.22000122070312) {
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
                            if (x[0] <= 12.080000400543213) {
                                votes[0] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        // tree #18
                        if (x[27] <= 209.0250015258789) {
                            votes[0] += 1;
                        }

                        else {
                            if (x[56] <= 37.614999771118164) {
                                if (x[37] <= 160.39500427246094) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }

                            else {
                                if (x[35] <= 278.06500244140625) {
                                    if (x[25] <= 247.06999969482422) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        if (x[56] <= 69.04499816894531) {
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
                        }

                        // tree #19
                        if (x[1] <= 20.734999656677246) {
                            if (x[6] <= 41.98000144958496) {
                                if (x[27] <= 275.83499908447266) {
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

                        else {
                            if (x[40] <= 245.71500396728516) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[38] <= 286.0600051879883) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }
                        }

                        // tree #20
                        if (x[53] <= 82.91500091552734) {
                            if (x[34] <= 306.0850067138672) {
                                if (x[37] <= 142.6750030517578) {
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
                            if (x[32] <= 313.3249969482422) {
                                votes[0] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
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
                            return "go";
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
