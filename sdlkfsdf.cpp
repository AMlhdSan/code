<!DOCTYPE html>
<html lang="zh-CN">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>macOS软件一文通</title>
  <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/github-markdown-css/5.1.0/github-markdown.min.css">
  <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
  <style>
    body {
      font-family: 'Arial', sans-serif;
      background-color: #f6f8fa;
      color: #24292f;
      padding: 20px;
      line-height: 1.6;
    }
    h1 {
      color: #0366d6;
    }
    h2, h3 {
      color: #0366d6;
      cursor: pointer;
      transition: color 0.3s;
    }
    h2:hover, h3:hover {
      color: #0056b3;
    }
    pre {
      background-color: #f1f8ff;
      padding: 10px;
      border-radius: 5px;
      overflow-x: auto;
    }
    a {
      color: #0366d6;
      text-decoration: none;
      transition: color 0.3s;
    }
    a:hover {
      color: #0056b3;
      text-decoration: underline;
    }
    .section-content {
      padding-left: 20px;
      margin-bottom: 20px;
      display: none;
    }
    .collapsible {
      font-weight: bold;
    }
    .collapsible::before {
      content: "▶ ";
      margin-right: 5px;
    }
    .active::before {
      content: "▼ ";
    }
    .tooltip {
      position: relative;
      display: inline-block;
      cursor: pointer;
    }
    .tooltip .tooltip-text {
      visibility: hidden;
      width: 150px;
      background-color: rgba(0, 0, 0, 0.75);
      color: #fff;
      text-align: center;
      border-radius: 5px;
      padding: 5px;
      position: absolute;
      z-index: 1;
      bottom: 125%; 
      left: 50%;
      margin-left: -75px;
      opacity: 0;
      transition: opacity 0.3s;
    }
    .tooltip:hover .tooltip-text {
      visibility: visible;
      opacity: 1;
    }
  </style>
</head>
<body class="markdown-body">

  <h1>macOS软件一文通</h1>
  <p>必装只装。</p>
  <p>网上看了很多推荐macOS的软件的文章，感觉内容都不咋的，几款非常好用的都没有推荐。现在就把我的传家宝给大家吧。</p>
  <p>本文和其他文章不同，不推荐大众化的东西，且内容多不为国产。</p>

  <h2 class="collapsible">1. 必装篇</h2>
  <div class="section-content">
    <p>这个真的是必装的。</p>

    <h3>(1) Homebrew</h3>
    <p>非开发人员勿入。</p>
    <p>官网：<a href="https://brew.sh" target="_blank">brew</a></p>
    <p>下载（终端命令）：<code>/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"</code></p>
    <p>brew可以下载你任何想要的东西：</p>
    <pre><code>brew search &lt;软件名&gt;</code></pre>
    <p>搜索（只有部分开源的在）</p>
    <pre><code>brew install &lt;软件名&gt;</code></pre>
    <p>下载（建议搜索出正确的名字再下载）</p>
    <pre><code>brew update</code></pre>
    <p>更新brew（其实在下软件之前都会进行的）</p>

    <h3>(2) Squirrel鼠须管 + oh-my-rime薄荷</h3>
    <p>鼠须管是中州韵输入法的一个，是macOS用户的首选，但是安装需要一点点的终端知识，不过不影响。</p>
    <p>官网：<a href="https://rime.im/" target="_blank">Rime</a></p>
    <p>Rime默认是中文繁体输入法，这时需要随便找一个输入框（什么Google地址栏，百度搜索栏，bing搜索栏都可以的）按下<kbd>control + ~</kbd>就可以切换了。</p>
    <p>然后在“设置”里面找到“输入法”，点击加号，输入鼠须管，点添加，然后左上角退出登录，重新登录就可以了。</p>
    <p>Rime最大的有点就是：个性化，但是需要很高的技术。所以我们就直接上壳子。</p>
    <p>但是这个UI有点丑，所以需要套一个壳子。</p>
    <p>薄荷就是这个壳子。</p>
    <p>我不喜欢叫他薄荷输入法，因为他不是一个输入法，而是一个rime的UI样式。具体操作看官网上的教程去。建议找官网的教程把竖行的输入换成横着的输入，好看一点。</p>
    <p>薄荷官网：<a href="https://www.mintimate.cc/" target="_blank">oh-my-rime</a></p>
    <p>最强大的输入法，没有之一。</p>

    <h3>(3) Acrobat Pro</h3>
    <p>PDF阅读器，官方的，超级超级好用，就是有亿点贵</p>
    <p><a href="https://acrobat.com/" target="_blank">Acrobat Pro</a></p>

    <h3>(4) Cleanshot X</h3>
    <p>可以画画，可以长截图，可以OCR，可以录屏，可以.....</p>
    <p>UI很好看</p>
    <p><a href="https://cleanshot.com/" target="_blank">CleanShot</a></p>
  </div>

  <h2 class="collapsible">2. 程序员必备</h2>
  <div class="section-content">
    <h3>(1) VS Code</h3>
    <p>不用介绍，直接官网：</p>
    <p><a href="https://visualstudio.microsoft.com/zh-hans/#vscode-section" target="_blank">VS Code</a></p>

    <h3>(2) Xcode</h3>
    <p>Apple原生的，适合macOS的软件开发（反正我不用）</p>
    <p>App Store自己下，免费的。</p>

    <h3>(3) Marktext</h3>
    <p>Markdown全能工具，UI巨好看。</p>
    <p>可以用Homebrew部署：</p>
    <pre><code>brew install mark-text --cask</code></pre>
    <p>它会自动移到applications文件夹。</p>
  </div>

  <h2 class="collapsible">3. 富哥必备</h2>
  <div class="section-content">
    <h3>(1) Parallels Desktop</h3>
    <p>虚拟机，渣机很卡。</p>

    <h3>(2) Surge</h3>
    <p>代理工具，超级超级超级超级贵，35美元第一年，第二年续费12美元。</p>

    <h3>(3) Final Cut Pro和Logic Pro</h3>
    <p>很贵，建议换区买，不然得倾家荡产。</p>
  </div>

  <script>
    $(document).ready(function() {
      $(".collapsible").click(function() {
        $(this).toggleClass("active");
        $(this).next(".section-content").slideToggle();
      });
    });
  </script>

</body>
</html>
