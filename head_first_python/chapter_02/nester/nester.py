def print_lol(the_list, indent = False, level = 0):
  """
  This function prints out a list recursively where each line will contain one
  entry from the list which may be a nested list.
  """
  for each_item in the_list:
    if isinstance(each_item, list):
      print_lol(each_item, indent, level + 1)
    else:
      if indent:
        for spaces in range(level):
          print("  ", end = '')
      print(each_item)