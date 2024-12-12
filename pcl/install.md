# 1.Ubuntu

## 1.1 必要包

```bash
sudo apt update
sudo apt install -y build-essential cmake libpcl-dev
```

- `libpcl-dev`：包含 PCL 的所有头文件和库。

---

# 2.Arch Linux

## 2.1 必要包

```bash
sudo pacman -Syu base-devel cmake
```

```bash
yay -S pcl
```