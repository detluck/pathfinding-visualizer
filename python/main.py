import pygame
from ui.ui import Ui

ui_test = Ui(30,30)

while( ui_test.running ):
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    ui_test.running = False

                grid = ui_test.draw_grid()
                ui_test.draw_all(grid)
             

pygame.quit()
