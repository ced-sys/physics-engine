#include <iostream>
#include <thread>
#include <chrono>
#include "vector2.hpp"
#include "rigidbody.hpp"

void clearScreen() {
    std::cout << "\033[2J\033[1;1H";  // ANSI escape code
}

int main() {
    // === Test vector math ===
    Vector2 a(3.0f, 4.0f);
    Vector2 b(1.0f, 2.0f);

    Vector2 sum = a + b;
    Vector2 diff = a - b;
    Vector2 scaled = a * 2.0f;

    std::cout << "Sum: (" << sum.x << ", " << sum.y << ")\n";
    std::cout << "Diff: (" << diff.x << ", " << diff.y << ")\n";
    std::cout << "Scaled: (" << scaled.x << ", " << scaled.y << ")\n";
    std::cout << "Length of a: " << a.length() << "\n";

    Vector2 norm = a.normalized();
    std::cout << "Normalized a: (" << norm.x << ", " << norm.y << ")\n\n";

    // === RigidBody Simulation ===
    std::cout << "--- RigidBody Simulation ---\n";

    RigidBody body(1.0f, Vector2(20.0f, 10.0f)); // Start in middle-top
    body.velocity = Vector2(2.0f, 0.0f);         // Initial push to the right

    Vector2 gravity(0.0f, -9.8f);

    const float dt = 0.1f;
    const int maxY = 20;
    const int maxX = 40;

    for (int i = 0; i < 300; ++i) {
        clearScreen();

        // Apply physics
        body.applyForce(gravity * body.mass);
        body.applyAirDrag(0.1f);
        body.applyGroundFriction(0.3f);
        body.update(dt);
        body.checkGroundCollision(0.6f);
        body.checkWallCollision(0.0f, maxX, 0.6f);

        // Clamp positions to screen
        int posY = std::max(0, std::min(maxY, static_cast<int>(body.position.y)));
        int posX = std::max(0, std::min(maxX, static_cast<int>(body.position.x)));

        // Draw vertical map
        for (int y = maxY; y >= 0; --y) {
            if (y == posY) {
                for (int x = 0; x <= posX; ++x) std::cout << " ";
                std::cout << "o\n";
            } else {
                std::cout << "\n";
            }
        }

        // Debug info
        std::cout << "Time: " << (i * dt) << "s - Position: ("
                  << body.position.x << ", " << body.position.y << ") - "
                  << "Velocity: (" << body.velocity.x << ", " << body.velocity.y << ")\n";

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    return 0;
}

