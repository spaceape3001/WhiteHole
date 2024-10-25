################################################################################
##
##  YOUR QUILL
##
################################################################################

add_library(yq_post SHARED
    post/post.cpp
    post/boxes/boxes.cpp
    post/commands/commands.cpp
    post/events/events.cpp
    post/messages/messages.cpp
    post/posts/posts.cpp
    post/replies/replies.cpp
    post/requests/requests.cpp
)

target_link_libraries(yq_post PUBLIC
    yq_core 
)

LinkTest(yq_post)

