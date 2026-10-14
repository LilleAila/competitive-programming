vector<vector<char>> rotated(columns, vector<char>(rows));

for (int i = 0; i < rows; i++) {
  for (int j = 0; j < columns; j++) {
    rotated[j][rows - 1 - i] = grid[i][j];
  }
}
