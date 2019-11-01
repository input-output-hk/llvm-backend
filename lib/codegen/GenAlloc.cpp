#include "kllvm/codegen/GenAlloc.h"
#include "llvm/Support/Casting.h"

namespace kllvm {

llvm::Function* koreHeapAlloc(std::string name, llvm::Module *module) {
  llvm::Type* size_type = llvm::Type::getInt64Ty(module->getContext());
  auto allocType = llvm::FunctionType::get(llvm::Type::getInt8PtrTy(module->getContext()), llvm::ArrayRef<llvm::Type*>(size_type), false);
  return castToFunctionOrAbort(valueFromFunctionCallee(module->getOrInsertFunction(name, allocType)));
}

llvm::Function* castToFunctionOrAbort(llvm::Value* value) {
  llvm::Function *func = llvm::dyn_cast<llvm::Function>(value);
  if (!func) {
    value->print(llvm::errs());
    abort();
  }
  return func;
}

llvm::Value* valueFromFunctionCallee(llvm::FunctionCallee callee) {
  return callee.getCallee();
}


}
