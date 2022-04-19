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
    
    char i, j, k;
    char cResult;

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
    for (i = 1; i < 90; i++) {
        
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
                for (k = resultLen; k > 0; k--) {
                    presultTemp[j][k] = presultTemp[j][k - 1];
                }
                for (k = 0; k < j; k++) {
                    presultTemp[j][k] = 0;
                }

                resultLen += j;
            }
            
            std::cout << "temp sub result: ";
            for (int rIndex = resultLen - 1; rIndex > -1; rIndex--) {
                std::cout << char(presultTemp[j][rIndex] + '0');
            }
            std::cout << std::endl;

            //memcpy(result, presultTemp[j], resultLen);
        }

        // add temp results to one result
        resultLen = sumTempResult(result, presultTemp, j, resultLen);


        std::cout << "temp result: ";
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


/*
int main()
{
    std::cout << "Hello Factorial!\n";

    char multiplicand[4];
    char multiplier[4];
    char result[200];
    char result1[200];
    char result2[200];
    char result3[200];
    char carry[1];
    char carryOld[1];

    char* paResultTemp[3] = { result3, result2, result1 };

    int multiplicandLen = 1;
    int multiplierLen = 1;
    int resultLen = 1;

    int i1;
    int i2;
    int iResult;
    int iCarry, iCarryOld, offset;

    int i, j, k, m;


    memset(result, 0x0, sizeof(result));
    result[0] = 1;
    carry[0] = 0;
    carryOld[0] = 0;

    for (i = 1; i < 101; i++) {
        memset(multiplicand, 0x0, sizeof(multiplicand));
        memcpy(multiplicand, result, resultLen);
        memset(multiplier, 0x0, sizeof(multiplier));
        _itoa_s(i, multiplier, 10);

        memset(result1, 0x0, sizeof(result1));
        memset(result2, 0x0, sizeof(result2));
        memset(result3, 0x0, sizeof(result3));

        multiplierLen = strlen(multiplier);
        for (j = multiplierLen-1; j > -1; j--) {
            i2 = multiplier[j] - '0';
            offset = multiplierLen - 1 - j;
            for (k = 0; k < multiplicandLen; k++) {
                i1 = multiplicand[k];
                iResult = i1 * i2;
                carryOld[0] = carry[0];
                iCarry = iResult / 10;
                iResult %= 10;

                paResultTemp[j][k + offset] = iResult + carryOld[0];
                carry[0] = iCarry;
            }

            // last bit
            paResultTemp[j][k + offset] = carry[0];
        }



        for (m = 0; m < 3; m++) {
        }

    }

}
*/
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
