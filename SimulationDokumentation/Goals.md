## Goals of the Software Development Simulation

[Goal: 1] The application helps to improve the understanding of side effects and
long-distance impact in software development.

![Caption text](goals.jpg)

@startuml
left to right direction
skinparam packageStyle rect
actor customer
rectangle checkout {
customer -- (checkout)
(checkout) .> (payment) : include
(help1) .> (checkout) : extends
(help2) .> (checkout) : extends
(help3) .> (checkout) : extends
(checkout) -- clerk
}
@enduml