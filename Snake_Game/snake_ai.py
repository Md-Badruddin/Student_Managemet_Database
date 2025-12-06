
import pygame
import random
import sys

# ===================== CONFIGURATION ===================== #
CELL_SIZE = 20           # size of one grid block in pixels
GRID_WIDTH = 30          # number of cells horizontally
GRID_HEIGHT = 30         # number of cells vertically
WIDTH = GRID_WIDTH * CELL_SIZE
HEIGHT = GRID_HEIGHT * CELL_SIZE

FPS = 10                 # game speed (frames per second)

# Colors (R, G, B)
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
GREEN = (0, 200, 0)
RED = (200, 0, 0)
BLUE = (0, 0, 200)
GRAY = (40, 40, 40)

# Directions as grid moves
DIRECTIONS = {
    "UP":    (0, -1),
    "DOWN":  (0, 1),
    "LEFT":  (-1, 0),
    "RIGHT": (1, 0)
}


# ===================== AI LOGIC (BACKEND) ===================== #
def get_ai_move(snake_body, food_pos, grid_width, grid_height):
    """
    Greedy Best-First Search:
    - Try all 4 directions
    - Reject moves that hit wall or snake body
    - Choose move that MINIMIZES Manhattan distance to food
    - Heuristic h(n) = |x1 - x2| + |y1 - y2|
    """

    head_x, head_y = snake_body[0]
    food_x, food_y = food_pos

    best_dir = None
    best_score = float("-inf")

    for dir_name, (dx, dy) in DIRECTIONS.items():
        new_x = head_x + dx
        new_y = head_y + dy
        new_head = (new_x, new_y)

        # 1. check wall collision
        if new_x < 0 or new_x >= grid_width or new_y < 0 or new_y >= grid_height:
            continue

        # 2. check self collision
        if new_head in snake_body:
            continue

        # 3. heuristic: negative manhattan distance (closer is better)
        distance = abs(new_x - food_x) + abs(new_y - food_y)
        score = -distance

        if score > best_score:
            best_score = score
            best_dir = dir_name

    # If all moves are bad (cornered), just keep moving in current direction
    if best_dir is None:
        best_dir = "RIGHT"

    return best_dir


# ===================== GAME LOGIC (FRONTEND + CONTROL) ===================== #
def draw_grid(surface):
    for x in range(0, WIDTH, CELL_SIZE):
        pygame.draw.line(surface, GRAY, (x, 0), (x, HEIGHT))
    for y in range(0, HEIGHT, CELL_SIZE):
        pygame.draw.line(surface, GRAY, (0, y), (WIDTH, y))


def draw_snake(surface, snake_body):
    for (x, y) in snake_body:
        rect = pygame.Rect(x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE)
        pygame.draw.rect(surface, GREEN, rect)


def draw_food(surface, food_pos):
    x, y = food_pos
    rect = pygame.Rect(x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE)
    pygame.draw.rect(surface, RED, rect)


def draw_text(surface, text, size, color, center):
    font = pygame.font.SysFont("Arial", size, True)
    render = font.render(text, True, color)
    rect = render.get_rect(center=center)
    surface.blit(render, rect)


def random_food_position(snake_body):
    """Return a random grid cell that is not occupied by the snake."""
    while True:
        x = random.randint(0, GRID_WIDTH - 1)
        y = random.randint(0, GRID_HEIGHT - 1)
        if (x, y) not in snake_body:
            return (x, y)


def game_loop():
    pygame.init()
    screen = pygame.display.set_mode((WIDTH, HEIGHT))
    pygame.display.set_caption("Snake AI - Greedy Best-First Search")
    clock = pygame.time.Clock()

    # Initial snake: length 3 in middle of grid
    start_x = GRID_WIDTH // 2
    start_y = GRID_HEIGHT // 2
    snake_body = [
        (start_x, start_y),
        (start_x - 1, start_y),
        (start_x - 2, start_y),
    ]
    direction = "RIGHT"
    food_pos = random_food_position(snake_body)
    score = 0
    game_over = False

    while True:
        # ========== HANDLE EVENTS (QUIT / RESTART) ========== #
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()

            # When game over allow restart with R
            if game_over and event.type == pygame.KEYDOWN:
                if event.key == pygame.K_r:   # restart
                    return
                elif event.key == pygame.K_q: # quit
                    pygame.quit()
                    sys.exit()

        screen.fill(BLACK)
        draw_grid(screen)

        if not game_over:
            # ========= AI DECIDES NEXT MOVE ========== #
            direction = get_ai_move(snake_body, food_pos, GRID_WIDTH, GRID_HEIGHT)
            dx, dy = DIRECTIONS[direction]

            # ========= UPDATE SNAKE POSITION ========== #
            head_x, head_y = snake_body[0]
            new_head = (head_x + dx, head_y + dy)

            # Check collisions
            hit_wall = (
                new_head[0] < 0 or new_head[0] >= GRID_WIDTH or
                new_head[1] < 0 or new_head[1] >= GRID_HEIGHT
            )
            hit_self = new_head in snake_body

            if hit_wall or hit_self:
                game_over = True
            else:
                snake_body.insert(0, new_head)  # add new head

                # Check if food eaten
                if new_head == food_pos:
                    score += 1
                    food_pos = random_food_position(snake_body)
                else:
                    snake_body.pop()  # remove tail (move forward)

        # ========= DRAW ELEMENTS ========== #
        draw_snake(screen, snake_body)
        draw_food(screen, food_pos)

        draw_text(screen, f"Score: {score}", 20, WHITE, (60, 15))

        if game_over:
            draw_text(screen, "GAME OVER", 40, BLUE, (WIDTH // 2, HEIGHT // 2 - 20))
            draw_text(screen, "Press R to Restart or Q to Quit",
                      24, WHITE, (WIDTH // 2, HEIGHT // 2 + 20))

        pygame.display.flip()
        clock.tick(FPS)


if __name__ == "__main__":
    while True:
        game_loop()   # allows restart after game over
