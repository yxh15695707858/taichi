#include <taichi/lang.h>
#include <taichi/testing.h>
#include <numeric>

int main() {
  using namespace taichi;
  using namespace taichi::Tlang;
  CoreState::set_trigger_gdb_when_crash(true);
  int n = 1;
  default_compile_config.use_llvm = true;
  for (int i = 0; i < 1; i++){
    Program prog(Arch::gpu);
    Global(a, f32);
    // Global(b, f32);
    layout([&]() { root.dense(Index(0), n).place(a); });
  };
  try {
    throw IRModified();
  } catch (IRModified) {
    TC_TAG;
  }
};

