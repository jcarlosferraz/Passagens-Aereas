# Diretórios do projeto
dir_src = src
dir_include = include
dir_obj = obj
dir_bin = bin

# Nome do executável
executable = $(dir_bin)/tp3.out

# Arquivos fontes e cabeçalhos
sources = main.cpp BancoDeDados.cpp Consulta.cpp Voo.cpp
headers = BancoDeDados.hpp Consulta.hpp Voo.hpp

# Lista de arquivos fontes e objetos
o_files = $(patsubst %.cpp,$(dir_obj)/%.o,$(sources))
src_files = $(addprefix $(dir_src)/, $(sources))
header_files = $(addprefix $(dir_include)/, $(headers))

# Compilador e flags
CXX = g++
CXXFLAGS = -Wall -I$(dir_include)

# Regra principal: "all"
all: $(executable)

# Regra para gerar o executável
$(executable): $(o_files)
	@mkdir -p $(dir_bin)
	$(CXX) $(o_files) -o $(executable)

# Regra para compilar arquivos objeto
$(dir_obj)/%.o: $(dir_src)/%.cpp $(header_files)
	@mkdir -p $(dir_obj)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpar os arquivos gerados
clean:
	rm -f $(dir_obj)/*.o
	rm -f $(dir_bin)/*

.PHONY: all clean
