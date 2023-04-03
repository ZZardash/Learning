import pygame
import random

pygame.init()
window_size = (800, 600)
screen = pygame.display.set_mode(window_size)
pygame.display.set_caption("Snake")
bg_color = (0, 0, 0)
block_size = 20
snake_speed = 200
font = pygame.font.SysFont("Arial", 25)
UP = 0
RIGHT = 1
DOWN = 2
LEFT = 3
class Snake:
    def __init__(self):
        self.length = 1
        self.positions = [((window_size[0] / 2), (window_size[1] / 2))]
        self.direction = random.choice([UP, RIGHT, DOWN, LEFT])
        self.color = (17, 24, 47)
    def get_head_position(self):
        return self.positions[0]
    def turn(self, point):
        if self.length > 1 and (point[0] * -1, point[1] * -1) == self.direction:
            return
        else:
            self.direction = point
    def move(self):
        cur = self.get_head_position()
        x, y = self.direction
        new = (((cur[0] + (x*block_size)) % window_size[0]), (cur[1] + (y*block_size)) % window_size[1])
        if new in self.positions[2:]:
            self.reset()
        else:
            self.positions.insert(0, new)
            if len(self.positions) > self.length:
                self.positions.pop()
    def reset(self):
        self.length = 1
        self.positions = [((window_size[0] / 2), (window_size[1] / 2))]
        self.direction = random.choice([UP, RIGHT, DOWN, LEFT])
    def draw(self, surface):
        for p in self.positions:
            r = pygame.Rect((p[0], p[1]), (block_size, block_size))
            pygame.draw.rect(surface, self.color, r)
            pygame.draw.rect(surface, (93, 216, 228), r, 1)
class Food:
    def __init__(self):
        self.position = (0, 0)
        self.color = (223, 163, 49)
        self.randomize_position()
    def randomize_position(self):
        self.position = (random.randint(0, (window_size[0] - block_size) / block_size) * block_size, random.randint(0, (window_size[1] - block_size) / block_size) * block_size)
    def draw(self, surface):
        r = pygame.Rect((self.position[0], self.position[1]), (block_size, block_size))
        pygame.draw.rect(surface, self.color, r)
        pygame.draw.rect(surface, (93, 216, 228), r, 1)
snake = Snake()
food = Food()
clock = pygame.time.Clock()
score = 0
game_over = False
while not game_over:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            game_over = True
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_UP:
                snake.turn(UP)
            elif event.key == pygame.K_DOWN:
                snake.turn(DOWN)
            elif event.key == pygame.K_LEFT:
                snake.turn(LEFT)
            elif event.key == pygame.K_RIGHT:
                snake.turn(RIGHT)
    snake.move()
    if snake.get_head_position() == food.position:
        snake.length += 1
        score += 1
        food.randomize_position()
    screen.fill(bg_color)
    snake.draw(screen)
    food.draw(screen)
    text = font.render("Score: " + str(score), True, (93, 216, 228))
    screen.blit(text, (5, 10))
    pygame.display.update()
    clock.tick(snake_speed)
pygame.quit()