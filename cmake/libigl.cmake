if(TARGET igl::core)
  return()
endif()

include(FetchContent)
  FetchContent_Declare(
  libigl
  SYSTEM
  GIT_REPOSITORY https://github.com/libigl/libigl.git
  GIT_TAG 5067c8b7eb85343af8f53cdeb0bfd1957ad59e04
  # GIT_TAG v2.4.0 original: changed for boost fix
)
FetchContent_MakeAvailable(libigl)
