int n = 100;
int i = 1;
int count;
while (true) {
    if (i > n) {
        break;
    }

    if (n % i != 0) {
        i = i + 1;
        continue;
    }
    else {
        count = count + 1;
    }
    i = i + 1;
}