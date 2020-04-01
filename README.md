# React Native Test App

React Native Test App provides test apps for all platforms as a package.

This is a work in progress. You can read and discuss the RFC at
[React Native: Discussions and Proposals](https://github.com/react-native-community/discussions-and-proposals/pull/204).

The package is still a bit cumbersome to consume, and requires manually writing
some of the configuration. We are currently working on making it easier, and
will write documentation when it becomes ready.

# Quick Start

Install `react-native-test-app` and `plop`. We will use Plop to generate the
test app:

```bash
yarn add react-native-test-app --dev
yarn add plop --dev
yarn plop --plopfile node_modules/react-native-test-app/plopfile.js --dest sample
```

`--dest` tells Plop where to generate the files. In this example, it will
generate files under `sample` folder. Choose the appropriate place to store your
test app, then answer a couple of questions:

```console
? What is the name of your test app? Sample
? Which platforms do you need test apps for? (Use arrow keys)
❯ all
  android
  ios
  macos
  windows
```

# Set up the Development Environment

We'll be using the Example app for all development of the React Native Test App.
Some platforms may require extra steps for the initial set up. Please follow the
steps below, then jump to the appropriate section(s) for the final steps.

Open a terminal and navigate to your clone of this repository:

```bash
cd react-native-test-app

# This step only needs to be done once, before we can install the
# Example app's dependencies. It is stored in
# `~/.config/yarn/link/react-native-test-app`. You can run `unlink`
# if you need to remove it later.
yarn link

# Install Example app's dependencies.
cd example
yarn

# Now we use the link we created earlier. This step needs to be run
# _after_ `yarn install` otherwise it will be overwritten.
yarn link "react-native-test-app"
```

## Android

TODO: https://github.com/microsoft/react-native-test-app/projects/1#card-32331906

## iOS

```bash
# Bundle the JS first so CocoaPods can find the assets.
yarn build:ios
pod install

# Finally, open the Xcode workspace.
open Example.xcworkspace
```

# Known Issues

## Invalid `Podfile` file: undefined method `[]' for nil:NilClass

This can occur if your package is iOS specific, i.e. it contains no `ios` folder
with an Xcode project. `react-native config` cannot detect your package if this
is missing. We can work around it by adding `react-native.config.js` at the root
of the package:

```js
module.exports = {
  project: {
    ios: {
      project: 'ReactTestApp-Dummy.xcodeproj'
    }
  }
};
```

# Contributing

This project welcomes contributions and suggestions. Most contributions require
you to agree to a Contributor License Agreement (CLA) declaring that you have
the right to, and actually do, grant us the rights to use your contribution. For
details, visit https://cla.opensource.microsoft.com.

When you submit a pull request, a CLA bot will automatically determine whether
you need to provide a CLA and decorate the PR appropriately (e.g., status check,
comment). Simply follow the instructions provided by the bot. You will only need
to do this once across all repositories using our CLA.

This project has adopted the
[Microsoft Open Source Code of Conduct](https://opensource.microsoft.com/codeofconduct/).
For more information see the
[Code of Conduct FAQ](https://opensource.microsoft.com/codeofconduct/faq/) or
contact [opencode@microsoft.com](mailto:opencode@microsoft.com) with any
additional questions or comments.
