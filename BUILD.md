# Build CrossingGame tren Windows voi MSYS2 UCRT64

Du an hien build thanh cong voi:

- CMake
- Ninja
- MSYS2 UCRT64 GCC
- SFML 3

## Cai thu vien

Mo PowerShell va chay:

```powershell
D:\msys2\usr\bin\pacman.exe -Syyu --noconfirm
D:\msys2\usr\bin\pacman.exe -S --needed --noconfirm mingw-w64-ucrt-x86_64-sfml
```

Neu dung MSYS2 o thu muc khac, thay `D:\msys2` bang duong dan MSYS2 tren may.

## Configure va build

```powershell
cmake -S . -B build-ninja -G Ninja -DCMAKE_CXX_COMPILER=D:/msys2/ucrt64/bin/g++.exe -DCMAKE_PREFIX_PATH=D:/msys2/ucrt64
cmake --build build-ninja
```

File chay duoc tao tai:

```text
bin\CrossingGame.exe
```

## Chay game

Nen them MSYS2 UCRT64 vao `PATH` truoc khi chay de Windows tim thay cac DLL phu:

```powershell
$env:PATH = "D:\msys2\ucrt64\bin;$env:PATH"
.\bin\CrossingGame.exe
```

## Ghi chu

- `CMakeLists.txt` da duoc cap nhat de dung SFML 3 target: `SFML::Graphics`, `SFML::Window`, `SFML::System`, `SFML::Audio`.
- Sau khi build, CMake tu copy cac DLL runtime ma target biet duoc vao `bin`.
- Neu co font `assets/fonts/arial.ttf` thi game se dung font do; neu khong co, game thu fallback sang `C:/Windows/Fonts/arial.ttf`.
