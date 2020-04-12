#ifdef _WIN32
#define _CRT_SECURE_NO_DEPRECATE
#define NL "\r\n"
#else
#define NL "\n"
#endif

#include <string>
#include <mmcobj.h>
#include "map/map.cpp"

using namespace std;

struct pnode {
    char ch; // char
    float p; // probability
};

static int pnode_compare(const void *elem1, const void *elem2) {
    const pnode a = *(pnode *) elem1;
    const pnode b = *(pnode *) elem2;
    if (a.p < b.p) return 1; // 1 - less (reverse for decreasing sort)
    else if (a.p > b.p) return -1;
    return 0;
}

class Coder {
private:
    int tsize; // table size (number of chars)
    pnode *ptable; // table of probabilities
    Map<char, string> codes; // codeword for each char

public:
    void Encode(const char *inputFilename, const char *outputFilename) {
        Map<char, int> freqs; // frequency for each char from input text
        int i;
        FILE *inputFile;
        inputFile = fopen(inputFilename, "r");
        char ch; // char
        unsigned total = 0;
        while (fscanf(inputFile, "%c", &ch) != EOF) {
            freqs.find(ch)->value++;
            total++;
        }
        tsize = (int) freqs.size();

        ptable = new pnode[tsize];
        float ftot = float(total);
        List<char>::Node *freqs_keys_head = freqs.get_keys()->get_head();
        List<int>::Node *freqs_value_head = freqs.get_values()->get_head();
        i = 0;
        while (freqs_keys_head != nullptr) {
            ptable[i].ch = freqs_keys_head->data;
            ptable[i].p = float(freqs_value_head->data) / ftot;
            freqs_keys_head = freqs_keys_head->next;
            freqs_value_head = freqs_value_head->next;
            i++;
        }
        qsort(ptable, tsize, sizeof(pnode), pnode_compare);

        EncShannon(0, tsize - 1);

        //  Opening output file
        //
        FILE *outputFile;
        outputFile = fopen(outputFilename, "wb");

        //  Outputing ptable and codes
        fprintf(outputFile, "%i" NL, tsize);
        for (i = 0; i < tsize; i++) {
            fprintf(outputFile, "%c\t%f\t%s" NL, ptable[i].ch, ptable[i].p, codes.find(ptable[i].ch)->value.c_str());
        }

        //  Outputing encoded text
        //
        fseek(inputFile, SEEK_SET, 0);
        fprintf(outputFile, NL);
        while (fscanf(inputFile, "%c", &ch) != EOF) {
            fprintf(outputFile, "%s", codes.find(ch));
        }

        codes.clear();
        delete[] ptable;

        fclose(outputFile);
        fclose(inputFile);
    }

    void Decode(const char *inputFilename, const char *outputFilename) {

        FILE *inputFile;
        inputFile = fopen(inputFilename, "r");

        fscanf(inputFile, "%i", &tsize);
        char ch, code[128];
        float p;
        int i;
        fgetc(inputFile); // skip end line
        for (i = 0; i < tsize; i++) {
            ch = fgetc(inputFile);
            fscanf(inputFile, "%f %s", &p, code);
            codes.find(ch)->value = code;
            fgetc(inputFile); // skip end line
        }
        fgetc(inputFile); // skip end line

        FILE *outputFile;
        outputFile = fopen(outputFilename, "w");

        string accum = "";

        List<char>::Node *codes_keys_head = codes.get_keys()->get_head();
        List<string>::Node *codes_values_head = codes.get_values()->get_head();

        while ((ch = fgetc(inputFile)) != EOF) {
            accum += ch;
            while (codes_keys_head != nullptr) {
                if (!strcmp(codes_values_head->data.c_str(), accum.c_str())) {
                    accum = "";
                    fprintf(outputFile, "%c", codes_keys_head->data);
                }
                codes_keys_head = codes_keys_head->next;
                codes_values_head = codes_values_head->next;
            }
        }
        fclose(outputFile);
        fclose(inputFile);
    }

private:
    void EncShannon(int li, int ri) {
        int i, isp;
        float p;
        float pfull;
        float phalf;

        if (li == ri) {
            return;
        } else if (ri - li == 1) {
            //  If interval consist of 2 elements then it's simple
            //
            codes.find(ptable[li].ch)->value += '0';
            codes.find(ptable[ri].ch)->value += '1';
        } else {
            //  Calculating sum of probabilities at specified interval
            //
            pfull = 0;
            for (i = li; i <= ri; ++i) {
                pfull += ptable[i].p;
            }

            //  Searching center
            //
            p = 0;
            isp = -1; // index of split pos
            phalf = pfull * 0.5f;
            for (i = li; i <= ri; ++i) {
                p += ptable[i].p;
                if (p <= phalf) {
                    codes.find(ptable[i].ch)->value += '0';
                } else {
                    codes.find(ptable[i].ch)->value += '1';
                    if (isp < 0) isp = i;
                }
            }

            if (isp < 0) isp = li + 1;

            //  Next step (recursive)
            //
            EncShannon(li, isp - 1);
            EncShannon(isp, ri);
        }
    }
};

int main(int argc, char **argv) {
    int i = 1;
    int dFlag = 0;
    char inputFilename[128];
    char outputFilename[128];

    printf(NL);

    i++;
    Coder *coder;
    coder = new Coder;
    if (!dFlag) {
        coder->Encode(inputFilename, outputFilename);
    } else {
        coder->Decode(inputFilename, outputFilename);
    }
    delete coder;
    return 0;
}