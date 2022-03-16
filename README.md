# React Native with MyScript iink

This is an old/defunct project that demonstrates using the MyScript iink
handwriting recognition toolkit from within a React Native application. It
was specifically developed for use on iOS devices.

See https://www.myscript.com for current information regarding MyScript iink.

Most of the work of exposing MyScript functionality to React Native is done in
`ios/crossword/SingleCharWidget/SingleCharWidget.swift`.

## Prerequisites

1. Xcode
1. Xcode Command Line Tools
1. Node.js


## Build and run

After cloning this repository `cd` into project directory and run the following
commands to install/build everything and launch the iOS Simulator:

```
npm install
react-native run-ios
```

## Troubleshooting

If `react-native` doesn't run try installing it globally:
```
npm install -g react-native-cli
```

## Refresh the application
Focus the iOS simulator and hit command-R to refresh the application. 
