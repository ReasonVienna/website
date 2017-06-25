#!/bin/bash

echo '{
  "name" : "bs-moment",
  "sources" : [
    {
      "dir": "src",
    }
  ],
  "bs-dependencies": [
  ]
}' > node_modules/bs-moment/bsconfig.json

cd node_modules/bs-moment
../bs-platform/bin/bsb -make-world
cd ../..
./node_modules/bs-platform/bin/bsb -make-world