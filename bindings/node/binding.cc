#include <napi.h>

typedef struct TSLanguage TSLanguage;

extern "C" TSLanguage *tree_sitter_edf();

// "tree-sitter", "currentLanguage" hance the name
Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports["name"] = Napi::String::New(env, "edf");
  auto language = Napi::External<TSLanguage>::New(env, tree_sitter_edf());
  exports["language"] = language;
  return exports;
}

NODE_API_MODULE(tree_sitter_edf_binding, Init)
