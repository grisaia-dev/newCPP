#include <iostream>
#include <vector>

std::variant<int, std::string, std::vector<int>> get_variant() {
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}

int main(void) {
    auto n = get_variant();
    if (std::holds_alternative<int>(n))
        std::cout << std::get<int>(n) * 2 << std::endl;

    if (std::holds_alternative<std::string>(n))
        std::cout << std::get<std::string>(n) << std::endl;

    if (std::holds_alternative<std::vector<int>>(n)) {
        for (unsigned i : std::get<std::vector<int>>(n))
            std::cout << i << " ";
        std::cout << std::endl;
    }

    return 0;
}