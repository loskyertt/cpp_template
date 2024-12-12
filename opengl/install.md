# 1. Ubuntu

## 1.1 必要包

```bash
sudo apt update
sudo apt install -y build-essential cmake libgl1-mesa-dev freeglut3-dev
```

- `libgl1-mesa-dev`：提供 OpenGL 的实现和开发头文件。
- `freeglut3-dev`：提供 FreeGLUT 的头文件和库。

## 1.2 可选包

- 如果需要 GLFW 和 GLEW：
```bash
sudo apt install libglfw3-dev libglew-dev
```

---

# 2.Arch Linux

## 2.1 必要包

以下是 Arch Linux 上的等效命令：
```bash
sudo pacman -Syu base-devel cmake mesa freeglut
```

- `mesa`：提供 OpenGL 的实现和开发头文件。
- `freeglut`：提供 FreeGLUT 的头文件和库。

## 2.2 可选包

- 如果需要 GLFW 和 GLEW:
```bash
sudo pacman -S glfw glew
```