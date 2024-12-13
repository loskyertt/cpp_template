# 1.模板的适用情况

| 案例 | 适用场景 | 备注 |
| ---------------- | ------------------------------------------------------------ | ---------------------------------------------------- |
| common | 常用模板，没有链接第三方库 | - |
| Qt_widget | Qt Widget 模板 | - |
| Qt_window | Qt Widget 模板 | - |

---

# 2.创建项目脚本

这是`.zshrc`的配置文件，可以直接复制到`.zshrc`中使用。如果是直接使用该配置，需要把模板放目录到`$HOME/workspace/`目录下，如果要放到其它目录，则需要修改脚本中对应的复制目录。要添加其它模板的话，在该基础上修改即可。

**参数说明：**
- `--common`参数：创建常用模板
- `--widget`参数：创建 Qt Widget 模板
- `--wiindow`参数：创建 Qt Window 模板

```bash
newproj() {
    # 检查是否提供了足够的参数
    if [ -z "$1" ] || [ -z "$2" ]; then
        echo "Usage: newproj <template_type> <project_name>"
        echo "template_type: --common | --widget | --window"
        return 1
    fi

    TEMPLATE_TYPE=$1
    PROJECT_NAME=$2

    # 检查目标目录是否存在
    if [ -d "$PROJECT_NAME" ]; then
        echo "Error: Directory '$PROJECT_NAME' already exists."
        return 1
    fi

    case "$TEMPLATE_TYPE" in
        --common)
            # 创建 common 模板
            mkdir -p "$PROJECT_NAME"
            cp -r "$HOME/workspace/cpp_template/common"/* "$PROJECT_NAME"/
            echo "Common project '$PROJECT_NAME' created successfully."
            ;;

        --widget)
            # 创建 Qt Widget 模板
            mkdir -p "$PROJECT_NAME"
            cp -r "$HOME/workspace/cpp_template/Qt_widget"/* "$PROJECT_NAME"/
            echo "Qt Widget project '$PROJECT_NAME' created successfully."
            ;;

        --window)
            # 创建 Qt Window 模板
            mkdir -p "$PROJECT_NAME"
            cp -r "$HOME/workspace/cpp_template/Qt_window"/* "$PROJECT_NAME"/
            echo "Qt Window project '$PROJECT_NAME' created successfully."
            ;;

        *)
            echo "Error: Unknown template type '$TEMPLATE_TYPE'"
            echo "Available template types: --common | --widget | --window"
            return 1
            ;;
    esac
}
```

使用示例：
```bash
newproj --common test
```
这会创建`test`项目，使用的`common`模板。

---

# 3.常用变量

```cmake
# Note：cmake中不区分大小写。

# 工程顶层目录
${CMAKE_SOURCE_DIR} ${PROJECT_SOURCE_DIR}

# 当前处理的 CMakeLists.txt 所在路径
${CMAKE_CURRENT_SOURCE_DIR}

# 返回 Cmakelists.txt 开头通过 PROJECT 指令定义的项目名称
${PROJECT_NAME}

# 分别用来重新定义最终结果（可执行文件、动静态库文件）的存放目录
${EXECUTABLE_OUTPUT_PATH} ${LIBRARY_OUTPUT_PATH}
```