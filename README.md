### Getting started

1. Clone the repo
2. `npm install`
3. `npm start`
4. Open browser and navigate to: http://localhost:8080/

### Intro

The project uses bucklescript build system and webpack under the hood. When you run `yarn start`, `bsb` will run in watch mode and in parallel webpack's dev server is started at http://localhost:8080/. Files build by `bsb` can be found in the `/lib` directory. The amazing thing about `bsb` is that it produces readable javascript files.
After these JS files are produced, `webpack-dev-server` uses them.

### Ideas for future TODOs

* Decode Json using https://github.com/BuckleTypes/bs-json
* Boilerplate for all ReasonML meetups (other countries)
* Profile pages for speakers/participants (way to share Code or Talks) - people can PR their profiles into the project
* Fetch YouTube and Meetup data into the page
* Links to all world-wide ReasonML meetups
