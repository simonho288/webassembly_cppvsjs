"use strict";

class Product {
  constructor(name, desc, price) {
    this._name = name;
    this._description = desc;
    this._price = price;
  }
}

function CreateProducts() {
  let products = [
    new Product("Product A", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. In tempor tempus mauris eu luctus. Sed convallis vehicula ligula at vestibulum. Nullam ultricies eu dolor quis gravida. Nullam lobortis mollis lorem.", 23.5),
    new Product("Product B", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aliquam dignissim velit sit amet dui posuere rutrum. Donec blandit lorem finibus bibendum placerat. Quisque justo enim, interdum aliquam viverra sed, cursus.", 16.8),
    new Product("Product C", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque rhoncus sagittis diam, tincidunt elementum ex elementum lacinia. Praesent ornare auctor rhoncus. Pellentesque habitant morbi tristique senectus et netus et malesuada.", 8.99),
    new Product("Product D", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam quis egestas ante. Aliquam erat volutpat. Nulla tristique laoreet dapibus. Morbi non magna ullamcorper, accumsan urna at, venenatis mauris. Vestibulum aliquam.", 3.25),
    new Product("Product E", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam dictum egestas orci et aliquam. Curabitur dapibus pharetra elit vel molestie. Nunc imperdiet accumsan molestie. Phasellus eu mauris risus. Nunc convallis.", 107.3),
    new Product("Product F", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Proin eu nibh volutpat, facilisis purus et, luctus risus. Aliquam volutpat urna a diam feugiat feugiat. Sed sed odio eleifend, dictum turpis.", 79.8),
    new Product("Product G", "Suspendisse potenti. Nulla feugiat cursus eros, ut fringilla mi mattis in. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc non lectus enim. Donec quis lorem sit amet augue semper.", 250.0),
    new Product("Product H", "Nam sed nulla a ex convallis accumsan non sit amet lectus. Suspendisse in tempus eros, hendrerit iaculis mi. Mauris in iaculis elit. Donec bibendum purus non enim tempus posuere. Nam.", 11.2),
    new Product("Product I", "Quisque sed egestas nunc. Aenean diam lorem, blandit at nisl at, maximus blandit velit. Praesent imperdiet eget augue sed commodo. Morbi bibendum eros ut leo commodo commodo. Integer nibh ante.", 97.2),
    new Product("Product J", "Aliquam id est nec lectus vulputate pretium. Nullam auctor tortor risus, vel pulvinar elit viverra in. Vestibulum suscipit magna in massa ornare posuere. Vestibulum ante ipsum primis in faucibus orci.", 123.0)
  ];
  return products;
}

function ProcessProducts() {
  let products = CreateProducts();
  let products1 = _.filter(products, (product) => {
    return product._price >= 20.0 && product._price <= 200.0;
  });
  let products2 = _.filter(products1, (product) => {
    return product._description.includes('pretium');
  });
  let products3 = _.sortBy(products2, '_price');
  return products3;
}

function ProcessMillionTimes() {
  let startTime = new Date();

  let products;
  for (let i = 0; i < 1000000; i++) {
    products = ProcessProducts();
  }
  let endTime = new Date();
  let timeDiff = (endTime - startTime) / 1000; // in second

  products.forEach((product) => {
    console.log(product);
  });

  return timeDiff;
}
