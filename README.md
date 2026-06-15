# MultiCast for OBS Studio

MultiCast is a multistream plugin for OBS Studio, branded for the DKStudio ecosystem.

This repository is a modified GPL fork of `obs-aitum-multistream`, with DKStudio branding, links, packaging changes, and local integration support for DKStudio desktop features.

## Current Status

- Rebranded to `MultiCast by DKStudio`
- Windows build verified locally
- Local auth bridge prepared for DKStudio desktop integration
- GitHub Actions build flow kept for Windows/macOS/Linux artifacts

## Build

### Stand-alone build on Windows

```powershell
cmake --preset windows-x64
cmake --build --preset windows-x64 --config RelWithDebInfo --parallel
cmake --install build_x64 --prefix .\release\RelWithDebInfo --config RelWithDebInfo
```

Built plugin files will appear under:

`release/RelWithDebInfo/multicast`

### GitHub Actions

For the easiest packaging flow, push this repository to GitHub and use the built-in Actions workflows.  
The Windows workflow can produce ready-to-download build artifacts and release assets.

See:

- [DKSTUDIO_PLAN.md](DKSTUDIO_PLAN.md)
- [PUSH_GUIDE.md](PUSH_GUIDE.md)

## License

This project remains distributed under GPL-2.0. See [LICENSE](LICENSE).

## Translations

Please read [TRANSLATIONS.md](TRANSLATIONS.md)
