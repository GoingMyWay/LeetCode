bool IsSubSeq(char *words, char *s) {   
    char *p = s;
    int len = strlen(words);
    for (int i = 0; i < len; i++) {
        p = strchr(p, words[i]);
        if (p == NULL) {
            return 0;
        }
        p += 1;
    }

    return 1;
}

int numMatchingSubseq(char * s, char ** words, int wordsSize) {
    int num = 0;
    for (int i = 0; i < wordsSize; i++) {
        if (IsSubSeq(words[i], s)) {
            num++;
        }
    }

    return num;
}