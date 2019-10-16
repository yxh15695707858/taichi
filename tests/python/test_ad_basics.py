import taichi as ti

def grad_test1():
  ti.reset()
  ti.cfg.use_llvm = True
  # ti.cfg.arch = ti.cuda

  x = ti.var(ti.i32)

  @ti.layout
  def place():
    ti.root.dense(ti.i, 1).place(x)

  @ti.kernel
  def func():
    x[0] = 0

  func.materialize()

  ti.reset()
  ti.lang_core.test_throw()


grad_test1()
