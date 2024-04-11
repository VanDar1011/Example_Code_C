#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
unsigned char sBox[256] = {
    0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
    0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
    0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
    0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
    0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
    0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
    0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
    0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
    0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
    0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
    0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
    0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
    0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
    0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
    0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
    0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16
};
unsigned char invSBox[256] = {
    0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb,
    0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb,
    0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e,
    0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25,
    0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92,
    0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84,
    0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06,
    0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b,
    0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73,
    0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e,
    0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b,
    0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4,
    0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f,
    0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef,
    0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61,
    0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d,

};
// Define subByte,invSubBytes
void subBytes(unsigned char* state) {
    for (int i = 0; i < 16; i++) {
        // Lấy giá trị hiện tại của state và sử dụng nó làm chỉ số trong S-box
        state[i] = sBox[state[i]];
    }
}
void equal(unsigned char* vecto, unsigned char* copyvecto) {
    for (int i = 0; i < 16; i++) {
        // Lấy giá trị hiện tại của state và sử dụng nó làm chỉ số trong S-box
        copyvecto[i] = vecto[i];
    }
}
void invSubBytes(unsigned char* state) {
    for (int i = 0; i < 16; i++) {
        // Lấy giá trị hiện tại của state và sử dụng nó làm chỉ số trong S-box ngược lại
        state[i] = invSBox[state[i]];
    }
}

// Hàm hiển thị trạng thái
void displayState(unsigned char* state) {
    for (int i = 0; i < 16; i++) {
        printf("%02x ", state[i]);
        if ((i + 1) % 4 == 0)
            printf("\n");
    }
}
// Define Round Keys (assume already generated)

// Function to perform AddRoundKey operation

unsigned char Rcon[40] = {
    0x01,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x08,0x00,0x00,0x00, 0x10,0x00,0x00,0x00, 0x20, 0x00,0x00,0x00,0x40,0x00,0x00,0x00, 0x80,0x00,0x00,0x00, 0x1B,0x00,0x00,0x00, 0x36
};

void SubWord(unsigned char* word) {
    for (int i = 0; i < 4; i++) {
        word[i] = sBox[word[i]];
    }
}

// Hàm xoay word sang trái một byte
void RotWord(unsigned char* word) {
    unsigned char temp = word[0];
    word[0] = word[1];
    word[1] = word[2];
    word[2] = word[3];
    word[3] = temp;
}

void ExpandKey(int loop, int block, unsigned char* key, unsigned char* expandedKey) {
    int bytesGenerated = 0;
    int indexRcon = 0;
    // Copy khóa ban đầu vào expanded key
    for (int i = 0; i < block; i++) {
        expandedKey[i] = key[i];
    }
    bytesGenerated += block;

    while (bytesGenerated <= 4 * 4 * (loop + 1)) {
        unsigned char temp[4];
        unsigned char temp1[4];
        for (int i = 0; i < 4; i++) {
            temp[i] = temp1[i] = expandedKey[i + bytesGenerated - 4];

        }

        RotWord(temp);
        SubWord(temp);

        for (int j = 0; j < 4; j++) {
            if (j < 4 && bytesGenerated % block < 4) {
                temp[j] = temp[j] ^ Rcon[indexRcon];
                indexRcon++;
                expandedKey[bytesGenerated] = temp[j] ^ expandedKey[bytesGenerated - block];
                bytesGenerated++;
            }
            else {

                expandedKey[bytesGenerated] = temp1[j] ^ expandedKey[bytesGenerated - block];

                bytesGenerated++;
            }
            
        }
        
    }
}
void ExpandKey1(int loop, int block, unsigned char* key, unsigned char* expandedKey)
{
    int bytesGenerated = 0;
    int indexRcon = 0;
    // Copy khóa ban đầu vào expanded key
    for (int i = 0; i < block; i++)
    {
        expandedKey[i] = key[i];
    }
    bytesGenerated += block;

    while (bytesGenerated <= 4 * 4 * (loop + 1))
    {
        unsigned char temp[4];
        unsigned char temp1[4];
        //  if(bytesGenerated % 16 == 0)
        for (int i = 0; i < 4; i++)
        {
            temp[i] = temp1[i] = expandedKey[i + bytesGenerated - 4];
        }
        //tempPrint(temp);
        //printf("\n");
        RotWord(temp);
        SubWord(temp);

        for (int j = 0; j < 4; j++)
        {
            // printf("temp sau rot va sub : ");
            if (j < 4 && bytesGenerated % block < 4)
            {

                // printf("%02x\n ", temp[j]);
                temp[j] = temp[j] ^ Rcon[indexRcon];
                // printf("Gia tri rcon : ");
                // printf("%02x\n ", Rcon[indexRcon]);
                indexRcon++;
                expandedKey[bytesGenerated] = temp[j] ^ expandedKey[bytesGenerated - block];
                // printf("Cuoi cung: ");
                // printf("%02x \n", expandedKey[bytesGenerated]);
                bytesGenerated++;
            }
            else
            {
                if (bytesGenerated == 12 * 4 || bytesGenerated == 20 * 4 || bytesGenerated == 28 * 4 || bytesGenerated == 36 * 4 || bytesGenerated == 44 * 4 || bytesGenerated == 52 * 4)
                {
                    for (int i = 0; i < 4; i++)
                    {
                        unsigned char temp2[4];
                        // unsigned char temp1[4];
                        temp2[i] = expandedKey[i + bytesGenerated - 4];
                        SubWord(temp2);
                        expandedKey[bytesGenerated + i] = temp2[i] ^ expandedKey[i + bytesGenerated - block];
                        //printf("%02x \n", expandedKey[bytesGenerated+i]);
                    }
                    bytesGenerated += 4;
                    break;
                }
                else
                {
                    expandedKey[bytesGenerated] = temp1[j] ^ expandedKey[bytesGenerated - block];

                    bytesGenerated++;
                }
            }
            // printf("\n");
        }
        // printf("line: %d",bytesGenerated);
    }
}

void shiftRows(unsigned char* state) {
    unsigned char temp;
    unsigned char temp1;
    unsigned char temp2;
    // Dịch hàng thứ hai sang trái 1 byte
    temp = state[4];
    state[4] = state[5];
    state[5] = state[6];
    state[6] = state[7];
    state[7] = temp;

    // Dịch hàng thứ ba sang trái 2 byte
    temp = state[8];
    temp1 = state[9];
    state[8] = state[10];
    state[9] = state[11];
    state[10] = temp;
    state[11] = temp1;

    // Dịch hàng thứ tư sang trái 3 byte
    temp = state[12];
    temp1 = state[13];
    temp2 = state[14];
    state[12] = state[15];
    state[13] = temp;
    state[14] = temp1;
    state[15] = temp2;
}
void invShiftRows(unsigned char* state) {
    unsigned char temp;
    unsigned char temp1;
    unsigned char temp2;

    // Dịch hàng thứ hai sang phải 1 byte
    temp = state[7];
    state[7] = state[6];
    state[6] = state[5];
    state[5] = state[4];
    state[4] = temp;

    // Dịch hàng thứ ba sang phải 2 byte
    temp = state[8];
    temp1 = state[9];
    state[8] = state[10];
    state[9] = state[11];
    state[10] = temp;
    state[11] = temp1;

    // Dịch hàng thứ tư sang phải 3 byte
    temp = state[12];
    state[12] = state[13];
    state[13] = state[14];
    state[14] = state[15];
    state[15] = temp;
}

// Function to perform MixColumns operation
//void MixColumns(uint8_t *state) {
    // Implementation here
//}

unsigned char xtime(unsigned char x)
{
    if (x >> 7) // a7 = 1
    {
        return ((x << 1) ^ 0x1B);
    }
    else
    {
        return (x << 1);
    }
}
//xtime la nhan voi x(02h)
// vi du goi :unsigned char result1 = xtime(0x57);
//
// Hàm MixColumn
//| 2  3  1  1 |   | b0 |   | 02b0 |
//| 1  2  3  1 | *| b1 | = | 0159 |
//| 1  1  2  3 |   | b2 |   | 01fd |
//| 3  1  1  2 |   | b3 |   | 03a1 |
void MixColumn(unsigned char* state)
{
    unsigned char tmp[4];

    for (int i = 0; i < 4; i++)
    {
        tmp[0] = xtime(state[i]) ^ (xtime(state[i + 4]) ^ state[i + 4]) ^ state[i + 8] ^ state[i + 12];
        tmp[1] = state[i] ^ xtime(state[i + 4]) ^ (xtime(state[i + 8]) ^ state[i + 8]) ^ state[i + 12];
        tmp[2] = state[i] ^ state[i + 4] ^ xtime(state[i + 8]) ^ (xtime(state[i + 12]) ^ state[i + 12]);
        tmp[3] = (state[i] ^ xtime(state[i])) ^ state[i + 4] ^ state[i + 8] ^ xtime(state[i + 12]);
        state[i] = tmp[0];
        state[i + 4] = tmp[1];
        state[i + 8] = tmp[2];
        state[i + 12] = tmp[3];
    }
}

unsigned char multiply(unsigned char a, unsigned char b)
{
    unsigned char result = 0;
    unsigned char carry;
    for (int i = 0; i < 8; ++i)
    {
        if (b & 1)
            result ^= a;
        carry = a & 0x80;
        a <<= 1;
        if (carry)
            a ^= 0x1B; // polynomial x^8 + x^4 + x^3 + x + 1
        b >>= 1;
    }
    return result;
}

// Hàm UnMixColumn
//| 14  11  13  9 |
//| 9   14  11  13|
//| 13  9   14  11|
//| 11  13  9   14 |
void UnMixColumn(unsigned char* state)
{
    unsigned char tmp[4];

    for (int i = 0; i < 4; i++)
    {
        tmp[0] = multiply(0x0E, state[i]) ^ multiply(0x0B, state[i + 4]) ^ multiply(0x0D, state[i + 8]) ^ multiply(0x09, state[i + 12]);
        tmp[1] = multiply(0x09, state[i]) ^ multiply(0x0E, state[i + 4]) ^ multiply(0x0B, state[i + 8]) ^ multiply(0x0D, state[i + 12]);
        tmp[2] = multiply(0x0D, state[i]) ^ multiply(0x09, state[i + 4]) ^ multiply(0x0E, state[i + 8]) ^ multiply(0x0B, state[i + 12]);
        tmp[3] = multiply(0x0B, state[i]) ^ multiply(0x0D, state[i + 4]) ^ multiply(0x09, state[i + 8]) ^ multiply(0x0E, state[i + 12]);

        state[i] = tmp[0];
        state[i + 4] = tmp[1];
        state[i + 8] = tmp[2];
        state[i + 12] = tmp[3];
    }
}

// AES encryption function
void AddRoundKey(unsigned char* state, unsigned char* roundKey) {
    state[0] ^= roundKey[0];
    state[1] ^= roundKey[4];
    state[2] ^= roundKey[8];
    state[3] ^= roundKey[12];
    state[4] ^= roundKey[1];
    state[5] ^= roundKey[5];
    state[6] ^= roundKey[9];
    state[7] ^= roundKey[13];
    state[8] ^= roundKey[2];
    state[9] ^= roundKey[6];
    state[10] ^= roundKey[10];
    state[11] ^= roundKey[14];
    state[12] ^= roundKey[3];
    state[13] ^= roundKey[7];
    state[14] ^= roundKey[11];
    state[15] ^= roundKey[15];

}

void xor (unsigned char* state1, unsigned char* state2) {
    for (int i = 0; i < 16; i++) {
        // Thực hiện phép XOR và lưu kết quả vào mảng result
        state1[i] = state1[i] ^ state2[i];
    }
}

void AES_Encrypt(int loop,int block,unsigned char* vecto, unsigned char* state, unsigned char* roundKeys) {
    xor (state, vecto);
    AddRoundKey(state, roundKeys);
    for (int round = 1; round < loop; round++) {
        subBytes(state);
        shiftRows(state);
        MixColumn(state);
        AddRoundKey(state, roundKeys + round * block);
    }
    subBytes(state);
    shiftRows(state);
    AddRoundKey(state, roundKeys + loop * block);
}

void AES_Invecrypt(int loop, int block, unsigned char* vecto, unsigned char* state1, unsigned char* roundKeys1) {
    AddRoundKey(state1, roundKeys1 + loop * block);
    for (int round = 1; round < loop; round++) {
        invShiftRows(state1);
        invSubBytes(state1);
        AddRoundKey(state1, roundKeys1 + (loop - round) * block);
        UnMixColumn(state1);
    }
    invShiftRows(state1);
    invSubBytes(state1);
    AddRoundKey(state1, roundKeys1);
    xor (state1, vecto); // Use the last Round Key
}

void displayExpandedKey(unsigned char* expandedKey) {
    for (int i = 0; i < 16; i++) {
        printf("%02x ", expandedKey[i]);
    }
}

void writeKeyToFile(const unsigned char* key, size_t keySize, FILE* file) {
    // Kiểm tra xem con trỏ file có hợp lệ không
    if (file == NULL) {
        fprintf(stderr, "Pointer is invalid\n");
        return;
    }
    // Ghi mảng key vào file dưới dạng ký tự
    for (size_t i = 0; i < keySize; i++) {
        fprintf(file, "%c", key[i]);
    }
}

void getInputKey(int *loop,int *block,unsigned char key[80]) {
    char input[80]; // Mảng để lưu 16 ký tự nhập từ bàn phím, kèm theo ký tự kết thúc chuỗi '\0'
    int inputLength; // Độ dài thực sự của chuỗi nhập vào

    // Nhập chuỗi từ bàn phím và kiểm tra độ dài
    while (1) {
        printf("Enter key(Must is 16 or 24 or 32 bit) : ");
        fgets(input, sizeof(input), stdin);
        inputLength = strlen(input);
        

        // Loại bỏ ký tự xuống dòng nếu có
        if (input[inputLength - 1] == '\n') {
            input[inputLength - 1] = '\0';
            inputLength--; // Giảm đi 1 vì đã loại bỏ ký tự xuống dòng
        }

        // Kiểm tra độ dài chuỗi nhập vào
        if (inputLength == 16) {
            *block = 16;
            *loop = 10;
            break;
        }
        else if (inputLength == 24) {
            *block = 24;
            *loop = 12;
            break;
        }
        else if (inputLength == 32) {
            *block = 32;
            *loop = 14;
            break;
        }
        else {
            printf("Number of character is not 16/24/32, please enter 16/24/32 character to execute code\n");
        }
        
    }
    printf("%d", *block);
    for (int i = 0; i < *block; i++) {
        key[i] = input[i]; // Giữ nguyên ký tự đầu vào
    }
}

int main() {
    clock_t start, end;
    int block = 0;
    int loop = 0;
    double cpu_time_used;
    int flag = 1;
    FILE* inputFile, * inputFileCir, * outputFile;
    unsigned char buffer[16];
    size_t bytesRead;
    int bufferIndex = 0;
    unsigned char key[80];
    unsigned char vecto[16] = { 0x31, 0x32, 0x33, 0x34, 0x35, 0x31, 0x32, 0x33, 0x34, 0x35, 0x31, 0x32, 0x33, 0x34, 0x35, 0x31 };
    unsigned char copyvecto[16] = { 0x31, 0x32, 0x33, 0x34, 0x35, 0x31, 0x32, 0x33, 0x34, 0x35, 0x31, 0x32, 0x33, 0x34, 0x35, 0x31 };
    unsigned char copyvecto1[16];
    unsigned char expandedKey[1000];
    int choice;
    do {
        // Menu
        printf("\nMenu:\n");
        printf("1. Encode\n");
        printf("2. Decryption\n");
        printf("3. Exit\n");
        printf("Select function (1, 2 or 3): ");
        scanf_s("%d", &choice);
        while (getchar() != '\n');
        switch (choice) {
        case 1:

            getInputKey(&loop,&block,key);

            start = clock();
            if (block == 16 || block == 24) {
                ExpandKey(loop, block, key, expandedKey);
            }
            else {
                ExpandKey1(loop, block, key, expandedKey);
            }
           
            if (fopen_s(&inputFile, "plaintext_input.txt", "r") != 0) {
                printf("Cannot open file plaintext_input.txt.\n");
                return 1;
            }
            if (fopen_s(&outputFile, "plaintext_output.txt", "w") != 0) {
                printf("Cannot open file plaintext_output.txt.\n");
                fclose(inputFile); // Đóng tập tin input trước khi thoát
                return 1;
            }
            while ((bytesRead = fread(buffer, 1, sizeof(buffer), inputFile)) > 0) {
                // Xử lý dữ liệu ở đây
                for (size_t i = bytesRead; i < sizeof(buffer); i++) {
                    buffer[i] = ' '; // Thêm ký tự space vào buffer nếu số byte đọc ít hơn 16
                }
                if (flag == 1) {
                    AES_Encrypt(loop, block ,copyvecto, buffer, expandedKey);

                    flag++;
                }
                else {

                    AES_Encrypt(loop,block,copyvecto, buffer, expandedKey);

                }

                equal(buffer, copyvecto);
                for (size_t i = 0; i < 16; i++) {
                    fprintf(outputFile, "%02X", buffer[i]);
                }
            }
            flag = 1;
            equal(vecto, copyvecto);
            //copyvecto = vecto;
            fclose(inputFile);
            fclose(outputFile);
            end = clock();
            cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
            printf("\nTime to execute: %f micro second\n", cpu_time_used* 1000);
            printf("Encrypted data has been written to the file planttext_output.txt");

            break;
        case 2:

            getInputKey(&loop,&block,key);
            start = clock();
         //   ExpandKey(loop, block,key, expandedKey);
            if (block == 16 || block == 24) {
                ExpandKey(loop, block, key, expandedKey);
            }
            else {
                ExpandKey1(loop, block, key, expandedKey);
            }
            if (fopen_s(&inputFileCir, "plaintext_output.txt", "r") != 0) {
                printf("Cannot open file plaintext_output.txt.\n");
                fclose(inputFileCir);
                return 1;
            }
            const char* filename = "ciphertext_output.txt";
            // Mở file để ghi dữ liệu
            FILE* file = fopen(filename, "w");
            if (file == NULL) {
                fprintf(stderr, "Can not open file  %s or file not exit\n", filename);
                return 1;
            }
            unsigned char byte1, byte2;
            // Đọc 2 giá trị liên tiếp từ tập tin và lưu vào buffer cho tới khi buffer đủ 16 phần tử
            while (fscanf_s(inputFileCir, "%02hhx%02hhx", &byte1, &byte2) == 2) {
                buffer[bufferIndex++] = byte1;
                buffer[bufferIndex++] = byte2;
                if (bufferIndex == 16) {
                    if (flag == 1) {
                        equal(buffer, copyvecto);
                        AES_Invecrypt(loop,block,vecto, buffer, expandedKey);
                        flag++;
                    }
                    else {
                        equal(buffer, copyvecto1);// hai gia tri dang khac nhau 
                        AES_Invecrypt(loop,block,copyvecto, buffer, expandedKey);
                        equal(copyvecto1, copyvecto);
                    }
                    writeKeyToFile(buffer, sizeof(buffer), file);
                    bufferIndex = 0; // Đặt lại chỉ số của buffer về 0 để vòng tiếp theo 
                }
            }
            flag = 1;
            equal(vecto, copyvecto);
            fclose(inputFileCir);
            fclose(file);
            end = clock();
            cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
            printf("\nTime to execute: %f micro second\n", cpu_time_used* 1000);
            printf("Decoded data has been written to the file ciphertext_out.txt");

            break;
        case 3:
            printf("Exit program.\n");
            break;
        default:
            printf("Function not exit.\n");
            break;
        }
    } while (choice != 3);

    return 0;
}
