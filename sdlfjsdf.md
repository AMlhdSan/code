证法一 我们考虑序列 $f(n)$ 的母函数
\[G(t) = \sum_{n=0}^{\infty} g(n)t^n\]
\[= (1+t^a + t^{2a} + \cdots)(1+t^b + t^{2b} + \cdots)(1+t^c + t^{2c} + \cdots)\]
\[= \cfrac{1}{(1-t^a)(1-t^b)(1-t^c)^a}\]

由于 $a, b, c$ 两两互质，分母多项式 $(1-t^a)(1-t^b)(1-t^c)$ 除了 $(1-t)^3$ 外没有其他重因式。设 $\omega = e^{2\pi i/a}, \tau = e^{2\pi i/b}, \rho = e^{2\pi i/c}$ 分别是 $a, b, c$ 次本原单位根,我们考虑部分分式:

\[\cfrac{1}{(1-t^a)(1-t^b)(1-t^c)} = \cfrac{h_0}{(1-t)} + \cfrac{h_1}{(1-t)^2} + \cfrac{h_2}{(1-t)^3}\]

\[+ \sum_{k=1}^{n-1} \cfrac{d_k}{1-\omega^k t} + \sum_{k=1}^{n-1} \cfrac{e_k}{1-r^k t} + \sum_{k=1}^{n-1} \cfrac{f_k}{1-\rho^k t}\]

其中各项分子 $h_0, h_1, h_2, d_1, \cdots, d_{n-1}, e_1, \cdots, e_{n-1}, f_1, \cdots, f_{n-1}$ 都是复数。我们计算 $\square$ 项分子 $d_k$, 给上述两端同时乘 $(1-\omega^k t)$ 之后, 再取 $t \to \omega^{-k}$ (或者直接认为 $1-\omega^k t = 0$ 也行)。此时部分分式的其余项都是 0, 所以

\[d_k = \lim_{t \to \infty} \cfrac{1-\omega^k t}{(1-\omega^k t)^a)(1-t^b)(1-t^c)}\]

\[= \cfrac{1}{a} \times \cfrac{1}{(1-\omega^{-kb})(1-\omega^{-kc})}\]

这样我们计算 $G(t)$ 的展开式的 $t^a$ 项系数:

\[f(n) = h_0 + h_1 \times (n+1) + h_2 \times \cfrac{(n+1)(n+2)}{2}\]

\[+ \sum_{k=1}^{n-1} d_k \omega^{kn} + \sum_{k=1}^{n-1} e_k t^{kn} + \sum_{k=1}^{n-1} f_k \rho^{kn}\]

注意到

\[\left| \sum_{k=1}^{n-1} d_k \omega^{kn} \right| \leq \sum_{k=1}^{n-1} |d_k|\]

\[= \cfrac{1}{a} \times \sum_{k=1}^{n-1} \cfrac{1}{|1-\omega^{-kb}| |1-\omega^{-kc}|}\]

\[\leq \cfrac{1}{a} \times \sum_{k=1}^{n-1} \cfrac{1}{|1-\omega^k|^2}\]

\[= \cfrac{a^2 - 1}{12a} < \cfrac{a}{12}\]

这里,最后一步的等号要用到后面证明的引理。同理可证 $\left| \sum_{k=1}^{n-1} e_k t^{kn} \right| <$

$\cfrac{b}{12}$ 和 $\left| \sum_{k=1}^{n-1} f_k \rho^k \right| < \cfrac{c}{12}$。
我们取 $\beta_2 = \cfrac{h_2}{2}$，$\beta_1 = h_1 + \cfrac{3}{2} h_2$，$\beta_0 = h_0 + h_1 + h_2$，
有：
$|\beta_2 n^2 + \beta_1 n + \beta_0 - f(n)| \leq \left| \sum_{k=1}^{n-1} d_k \omega^k \right| + \left| \sum_{k=1}^{n-1} e_k r^k \right| + \left| \sum_{k=1}^{n-1} f_k \rho^k \right|$
$< \cfrac{a + b + c}{12}$。

倒数第二步需要[引理]，对任意正整数 $m$，有
$\sum_{k=1}^{n-1} \cfrac{1}{\sin^2 \cfrac{k\pi}{m}} = \cfrac{m^2 - 1}{3}$
这等价于证明
$\sum_{k=1}^{n-1} \cot^2 \cfrac{k\pi}{m}} = \cfrac{m^2 - 3m + 2}{3}$

对 $\theta \in A = \left( \cfrac{\pi}{m}, \cfrac{2\pi}{m}, \cdots, \cfrac{(m-1)\pi}{m} \right)$，有
$(\cos \theta + i \sin \theta)^m = \cos(m\theta) + i \sin(m\theta) = \pm 1$,

考虑虚部
$C_m^1 \sin \theta \cos^{m-1} \theta - C_m^2 \sin^2 \theta \cos^{m-2} \theta + C_m^3 \sin^3 \theta \cos^{m-4} \theta + \cdots = 0$,

即
$C_m^1 (\cot \theta)^{m-1} - C_m^2 (\cot \theta)^{m-3} + C_m^3 (\cot \theta)^{m-5} + \cdots = 0$,

即
$(\cot \cfrac{k\pi}{m}, k = 1, 2, \cdots, m-1)$
满足上面的关于 $\cot \theta$ 的 $m-1$ 次多项式。

根据韦达定理，$m-1$ 个根之和为 $\sigma_1 = 0$，两两乘积之和为
$\sigma_2 = -\cfrac{C_m^1}{C_m^1} = -\cfrac{(m-1)(m-2)}{6}$,

因此 $m-1$ 个根的平方和为
$\sum_{k=1}^{n-1} \cot^2 \cfrac{k\pi}{m}} = \sigma_1^2 - 2\sigma_2 = \cfrac{m^2 - 3m + 2}{3}$。

证法二 由对称性不妨设 $a \leq b \leq c$。若 $a = b = c = 1$，则 $f(n)$ 等于把 $n$ 写成三个非负整数和的方法数，即 $C_{n+2}^2$，此时取 $a = \cfrac{1}{2}$，$\beta = \cfrac{3}{2}$，$\gamma = 1$ 可使误