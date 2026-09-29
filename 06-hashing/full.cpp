#include <iostream>
#include <unordered_map>
using namespace std;

int main() {

  int arr[] = {1, 2, 3, 1, 2, 3, 2, 1, 4, 5, 6};

  unordered_map<int, int> freq;

  // 1. insert()
  freq.insert({10, 100});
  freq.insert({20, 200});

  // 2. operator[] - insert / update
  freq[1]++;
  freq[2]++;
  freq[3]++;

  // 3. at()
  cout << "at(1): " << freq.at(1) << endl;

  // 4. size()
  cout << "size(): " << freq.size() << endl;

  // 5. empty()
  cout << "empty(): " << freq.empty() << endl;

  // 6. count()
  cout << "count(2): " << freq.count(2) << endl;
  cout << "count(99): " << freq.count(99) << endl;

  // 7. find()
  auto it = freq.find(2);

  if (it != freq.end()) {
    cout << "find(2): " << it->first << " -> " << it->second << endl;
  }

  // 8. erase()
  freq.erase(10);

  cout << "After erase(10), size(): " << freq.size() << endl;

  // 9. begin() and end()
  cout << "\nUsing begin() and end():" << endl;

  for (auto it = freq.begin(); it != freq.end(); it++) {
    cout << it->first << " -> " << it->second << endl;
  }

  // 10. range-based for loop
  cout << "\nUsing range-based for loop:" << endl;

  for (auto x : freq) {
    cout << x.first << " -> " << x.second << endl;
  }

  // 11. clear()
  freq.clear();

  cout << "\nAfter clear():" << endl;
  cout << "size(): " << freq.size() << endl;
  cout << "empty(): " << freq.empty() << endl;

  // -----------------------------------
  // Hash-specific functions
  // -----------------------------------

  // Add some values again
  freq[1] = 3;
  freq[2] = 3;
  freq[3] = 2;
  freq[4] = 1;

  // 12. bucket_count()
  cout << "\nbucket_count(): " << freq.bucket_count() << endl;

  // 13. bucket()
  cout << "bucket(1): " << freq.bucket(1) << endl;

  // 14. bucket_size()
  int bucket = freq.bucket(1);

  cout << "bucket_size(" << bucket << "): " << freq.bucket_size(bucket) << endl;

  // 15. load_factor()
  cout << "load_factor(): " << freq.load_factor() << endl;

  // 16. max_load_factor()
  cout << "max_load_factor(): " << freq.max_load_factor() << endl;

  // 17. max_bucket_count()
  cout << "max_bucket_count(): " << freq.max_bucket_count() << endl;

  return 0;
}