// factorial.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

// 93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000

// analyse:
//  1      1     2     6      24    120     720     5040    40320
//* 1    * 2   * 3   * 4    *  5    * 6     * 7      * 8       *9
//----   ---  ----  ----   -----   -----   -----   ------  -------
//  1      2     6    24     120    720    5040    40320   362880

//  362880     3628800       39916800
//    * 10       *  11          *  12
//---------  ----------    -----------
//  000000     3628800       79833600
// 362880     3628800       39916800
//---------  -----------   -----------
// 3628800    39916800      479001600

#include <iostream>

// multiplier is 1 bit

// param describe:
// result, OUTPUT, char array, length not less multiplicanLen+1
// multiplicand, INPUT, char array, example(5040 is [...5, 0, 4, 0] )
// multiplicand, INPUT, int, example(5040's length is 4)
// multiplier, INPUT, char, a decimal digit, someone of 0--9.
// return value, int, the result length. < 1 is failed.
int multiOneDigit(char result[], char multiplicand[], int multiplicandLen, char multiplier);

int sumTempResult(char result[], char* presultTemp[], char j, int resultLen);

int main()
{
    char result[200];
    char resultTemp1[200];
    char resultTemp2[200];
    char resultTemp3[200];

    char* presultTemp[3];

    char multiplicand[200];
    char multiplier[4];
    
    unsigned char i, j, k;
    unsigned char cResult;

    int resultLen = 1;
    int multiplicandLen = 0;
    int multiplierLen = 0;

    int multiplierTemp;

    memset(resultTemp1, 0x0, sizeof(resultTemp1));
    memset(resultTemp2, 0x0, sizeof(resultTemp2));
    memset(resultTemp3, 0x0, sizeof(resultTemp3));

    presultTemp[0] = resultTemp1;
    presultTemp[1] = resultTemp2;
    presultTemp[2] = resultTemp3;

    memset(result, 0x0, sizeof(result));
    result[0] = 1;
    for (i = 1; i < 101; i++) {
        
        memcpy(multiplicand, result, resultLen);
        multiplicandLen = resultLen;
        memset(result, 0x0, sizeof(result));

        memset(multiplier, 0x0, sizeof(multiplier));
        multiplierTemp = i;
        j = 0;
        do {
            multiplier[j] = multiplierTemp % 10;
            multiplierTemp /= 10;
            j++;
        } while (multiplierTemp > 0);
        multiplierLen = j;
        
        for (j = 0; j < multiplierLen; j++) {

            memset(presultTemp[j], 0x0, 200);
            resultLen = multiOneDigit(presultTemp[j], multiplicand, multiplicandLen, multiplier[j]);

            if (j > 0) {
                for (k = resultLen-1+j; k > 0; k--) {
                    presultTemp[j][k] = presultTemp[j][k - j];
                }
                for (k = 0; k < j; k++) {
                    presultTemp[j][k] = 0;
                }

                resultLen += j;
            }
            
            std::cout << (int)i << "'s sub result_" << (int)j << ": ";
            for (int rIndex = resultLen - 1; rIndex > -1; rIndex--) {
                std::cout << char(presultTemp[j][rIndex] + '0');
            }
            std::cout << std::endl;

            //memcpy(result, presultTemp[j], resultLen);
        }

        // add temp results to one result
        resultLen = sumTempResult(result, presultTemp, j, resultLen);


        std::cout << (int)i <<  "'s factorial is: ";
        for (int rIndex = resultLen - 1; rIndex > -1; rIndex--) {
            std::cout << char(result[rIndex] + '0');
        }
        std::cout << std::endl;

    }

}

int multiOneDigit(char result[], char multiplicand[], int multiplicandLen, char multiplier)
{
    int resultLen = multiplicandLen;
    int j;
    char cResult;
    char carry;

    carry = 0;

    for (j = 0; j < multiplicandLen; j++) {
        cResult = multiplicand[j] * multiplier;

        result[j] = cResult % 10 + carry;
        carry = cResult / 10;

        if (result[j] >= 10) {
            carry += result[j] / 10;
            result[j] %= 10;
        }

    }

    if (carry > 0) {
        result[j] = carry;
        resultLen++;
    }

    return resultLen;
}

int sumTempResult(char result[], char* presultTemp[], char trNum, int resultLen)
{
    int i;
    int resultLenNew = resultLen;
    char cResult;
    char carry;

    carry = 0;
    for (i = 0; i < resultLen; i++) {
        
        cResult = 0;
        for (char j = 0; j < trNum; j++) {
            cResult += presultTemp[j][i];
        }

        result[i] = cResult % 10 + carry;
        carry = cResult / 10;

        if (result[i] >= 10) {
            carry += result[i] / 10;
            result[i] %= 10;
        }
    }

    if (carry > 0) {
        result[i] = carry;
        resultLenNew++;
    }

    return resultLenNew;
}
