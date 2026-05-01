if(TARGET igl::core)
  return()
endif()

include(FetchContent)
  FetchContent_Declare(
  libigl
  SYSTEM
  GIT_REPOSITORY https://github.com/rjc8237/libigl.git
  #GIT_TAG 5067c8b7eb85343af8f53cdeb0bfd1957ad59e04
  #GIT_TAG v2.4.0
  GIT_TAG penner
)
FetchContent_MakeAvailable(libigl)
