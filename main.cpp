#include <ctime>
#ifdef __EMSCRIPTEN__
  #include <emscripten/emscripten.h>
#else
  #define EMSCRIPTEN_KEEPALIVE
#endif
#include "headers.h"
#include "product.h"

auto CreateProducts() {
  // Create 10 demo products
  vector<Product> products = {
    {"Product A", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. In tempor tempus mauris eu luctus. Sed convallis vehicula ligula at vestibulum. Nullam ultricies eu dolor quis gravida. Nullam lobortis mollis lorem.", 23.5},
    {"Product B", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aliquam dignissim velit sit amet dui posuere rutrum. Donec blandit lorem finibus bibendum placerat. Quisque justo enim, interdum aliquam viverra sed, cursus.", 16.8},
    {"Product C", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque rhoncus sagittis diam, tincidunt elementum ex elementum lacinia. Praesent ornare auctor rhoncus. Pellentesque habitant morbi tristique senectus et netus et malesuada.", 8.99},
    {"Product D", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam quis egestas ante. Aliquam erat volutpat. Nulla tristique laoreet dapibus. Morbi non magna ullamcorper, accumsan urna at, venenatis mauris. Vestibulum aliquam.", 3.25},
    {"Product E", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam dictum egestas orci et aliquam. Curabitur dapibus pharetra elit vel molestie. Nunc imperdiet accumsan molestie. Phasellus eu mauris risus. Nunc convallis.", 107.3},
    {"Product F", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Proin eu nibh volutpat, facilisis purus et, luctus risus. Aliquam volutpat urna a diam feugiat feugiat. Sed sed odio eleifend, dictum turpis.", 79.8},
    {"Product G", "Suspendisse potenti. Nulla feugiat cursus eros, ut fringilla mi mattis in. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc non lectus enim. Donec quis lorem sit amet augue semper.", 250.0},
    {"Product H", "Nam sed nulla a ex convallis accumsan non sit amet lectus. Suspendisse in tempus eros, hendrerit iaculis mi. Mauris in iaculis elit. Donec bibendum purus non enim tempus posuere. Nam.", 11.2},
    {"Product I", "Quisque sed egestas nunc. Aenean diam lorem, blandit at nisl at, maximus blandit velit. Praesent imperdiet eget augue sed commodo. Morbi bibendum eros ut leo commodo commodo. Integer nibh ante.", 97.2},
    {"Product J", "Aliquam id est nec lectus vulputate pretium. Nullam auctor tortor risus, vel pulvinar elit viverra in. Vestibulum suscipit magna in massa ornare posuere. Vestibulum ante ipsum primis in faucibus orci.", 123.0}
  };

  return products;
}

auto ProcessProducts() {
  vector<Product> products_orig = CreateProducts();

  // Find the products which the price between 100 & 150
  vector<Product> products1;
  copy_if(products_orig.begin(), products_orig.end(), std::back_inserter(products1), [](const Product& p) {
    return (p._price >= 20.0) && (p._price <= 200.0);
  });

  // Find the products which the product description contains "pretium"
  vector<Product> products2; // working products
  copy_if(products1.begin(), products1.end(), std::back_inserter(products2), [](const Product& p) {
    return (p._description.find("pretium") != std::string::npos);
  });

  // Sort the products by price ascending using Lambda (requires C++ 14)
  sort(products2.begin(), products2.end(), Product::CompareByPrice);

  return products2;
}

#ifdef __cplusplus
extern "C" {
#endif

// Exposes this function to javascript.
double EMSCRIPTEN_KEEPALIVE ProcessMillionTimes(int argc, char** argv) {
  clock_t begin = clock();

  vector<Product> products;
  for (int i = 0; i < 1000000; i++) {
    products = ProcessProducts();
  }

  clock_t end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

  // Print all final product(s)
  for (auto it : products) {
    cout << it << endl;
  }

  return elapsed_secs;
}

#ifdef __cplusplus
}
#endif

int main()
{
#if !defined(NDEBUG)
  double time = ProcessMillionTimes(0, 0);
  cout << "Elapsed second: " << time << endl;
  getchar();
#endif

  return 0;
}
