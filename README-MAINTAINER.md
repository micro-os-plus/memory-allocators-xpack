[![license](https://img.shields.io/github/license/micro-os-plus/memory-allocators-xpack)](https://github.com/micro-os-plus/memory-allocators-xpack/blob/xpack/LICENSE)
[![GitHub issues](https://img.shields.io/github/issues/micro-os-plus/memory-allocators-xpack.svg)](https://github.com/micro-os-plus/memory-allocators-xpack/issues)
[![GitHub pulls](https://img.shields.io/github/issues-pr/micro-os-plus/memory-allocators-xpack.svg)](https://github.com/micro-os-plus/memory-allocators-xpack/pulls)

# Maintainer info

## Project repository

The project is hosted on GitHub:

- https://github.com/micro-os-plus/memory-allocators-xpack.git

To clone it:

```
git clone https://github.com/micro-os-plus/memory-allocators-xpack.git template-xpack.git
```

## Prerequisites

A recent [xpm](https://xpack.github.io/xpm/), which is a portable
[Node.js](https://nodejs.org/) command line application.

## Publish to npmjs.com

- select the `xpack-develop` branch
- commit all changes
- update `CHANGELOG.md`; commit with a message like _CHANGELOG: prepare v0.1.2_
- `npm pack` and check the content of the archive, which should list
  only the `package.json`, the `README.md`, `LICENSE` and `CHANGELOG.md`;
  possibly adjust `.npmignore`
- `npm version patch`, `npm version minor`, `npm version major`
- push the `xpack-develop` branch to GitHub
- `npm publish --tag next` (use `--access public` when publishing for
  the first time)

The version is visible at:

- https://www.npmjs.com/package/@micro-os-plus/memory-allocators?activeTab=versions

## Test

Test the package.

## Update the repo

When the package is considered stable:

- with Sourcetree
- merge `xpack-develop` into `xpack`
- push to GitHub

## Tag the npm package as `latest`

When the release is considered stable, promote it as `latest`:

- `npm dist-tag ls @micro-os-plus/memory-allocators`
- `npm dist-tag add @micro-os-plus/memory-allocators@1.2.3 latest`
- `npm dist-tag ls @xpack-dev-tools/template`

## Announce to the community

Post an announcement to the forum or on Twitter.
