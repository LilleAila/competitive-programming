int main() {
  int a = 0;
  int b = n-1; // or xs.size()-1, the last index
  int result = -1;

  while (a <= b) {
    int mid = (a + b) / 2; // (or `a+(b-a)/2` to avoid overflow)
    int x = xs[mid];
    if (x == target) {
      result = mid;
      break;
    }
    else if (x < target) a = mid + 1;
    else b = mid - 1;
  }
}
