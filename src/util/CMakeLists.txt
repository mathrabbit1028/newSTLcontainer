add_library(util_obj OBJECT SecurePRNG.c
                            TimerWind.c
                            xoshiro256starstar.c)

target_link_libraries(util_obj PUBLIC bcrypt)